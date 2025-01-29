/* $NetBSD: iconv-bridge.c,v 1.1 2025/01/29 13:21:53 pho Exp $
 *
 * Our bootkits are built with native iconv, which means their
 * libHSbase-*.a have references to native iconv symbols (iconv_open,
 * iconv, ...). However, when PREFER.iconv is set to "pkgsrc", our
 * infrastructure pulls in GNU libiconv in ${BUILDLINK_DIR}/lib. The
 * stage-0 compiler (from bootkit) then attempts to link its libHSbase with
 * GNU libiconv because the "base" library has metadata that instructs the
 * compiler to link it with "-liconv"[*1], but this fails because they
 * don't provide the same set of symbols[*2]. The same would happen when a
 * bootkit is built with GNU libiconv but the user prefers native iconv.
 *
 * As a workaround we build a library containing symbols for both of them,
 * and inject it into the command line of the stage-0 compiler to resolve
 * missing symbols of the opposite side[*3]. We abuse the fact that
 * <iconv.h> headers don't really affect ABI (aside from symbols names
 * getting renamed) because the only type they define is iconv_t, which is
 * just a pointer type. In theory implementations might provide iconv_t of
 * different sizes and thus introducing ABI incompatibility, but in
 * practice all of existing implementations define it as a pointer, so
 * calling iconv() from libiconv() should be okay as long as we don't try
 * to use two implementations at once.
 *
 * Note that this problem only affects the stage-0 compiler. The final
 * product to be installed (stage-2) uses whatever implementation the user
 * prefers, that is, this library is only used while building stage-1 but
 * never used nor installed after that.
 *
 * [*1]: Only on platforms where native iconv is in a separate library but
 *       not a part of libc. Darwin is one of such platforms, while NetBSD
 *       is not.
 *
 * [*2]: jperkin@ reported this happened even if GNU libiconv was *not*
 *       buildlinked. The mere existence of pkgsrc libiconv caused the same
 *       issue. This is plausible, because GHC needs to record whatever
 *       {C,CPP,LD}FLAGS used during build so that it can link user
 *       programs with external libraries from pkgsrc, such as libffi and
 *       libgmp. Though pho@ could not reproduce this exact failure mode.
 *
 * [*3]: -liconv-bridge must not appear before -lc, otherwise this breaks
 *       platforms where native iconv is a part of libc, because dummy
 *       definitions in the bridge gets preferred over the real ones.
 */
#include <sys/types.h>

typedef void* iconv_t;

/* Native iconv */
iconv_t iconv_open(const char* tocode, const char* fromcode);
int iconv_close(iconv_t cd);
size_t iconv(iconv_t cd,
             char** restrict src, size_t* restrict srcleft,
             char** restrict dst, size_t* restrict dstleft);

/* GNU iconv */
iconv_t libiconv_open(const char* tocode, const char* fromcode);
int libiconv_close(iconv_t cd);
size_t libiconv(iconv_t cd,
                char** restrict src, size_t* restrict srcleft,
                char** restrict dst, size_t* restrict dstleft);

/* These two variants cannot both be in the same module so we have to
 * compile this file twice. Otherwise they will infinitely call each other
 * and eventually segfault.
 */
#if NATIVE
iconv_t iconv_open(const char* tocode, const char* fromcode) {
    return libiconv_open(tocode, fromcode);
}

int iconv_close(iconv_t cd) {
    return libiconv_close(cd);
}

size_t iconv(iconv_t cd,
             char** restrict src, size_t* restrict srcleft,
             char** restrict dst, size_t* restrict dstleft) {
    return libiconv(cd, src, srcleft, dst, dstleft);
}

#else /* NATIVE */
iconv_t libiconv_open(const char* tocode, const char* fromcode) {
    return iconv_open(tocode, fromcode);
}

int libiconv_close(iconv_t cd) {
    return iconv_close(cd);
}

size_t libiconv(iconv_t cd,
                char** restrict src, size_t* restrict srcleft,
                char** restrict dst, size_t* restrict dstleft) {
    return iconv(cd, src, srcleft, dst, dstleft);
}

#endif /* NATIVE */
