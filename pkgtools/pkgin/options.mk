# $NetBSD: options.mk,v 1.5 2024/12/06 10:19:35 jperkin Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pkgin
PKG_SUPPORTED_OPTIONS=	pkgin-prefer-gzip pkgin-static

.include "../../mk/bsd.prefs.mk"

#
# Prefer pkg_summary.gz instead of .bz2 or .xz on hosts that are likely to be
# slower or have limited memory where the higher compression can cause issues.
#
PROBABLY_SLOW_ARCHS=	alpha hppa i386 m68k powerpc sh3eb sh3el sparc vax
.if !empty(PROBABLY_SLOW_ARCHS:M${MACHINE_ARCH})
PKG_SUGGESTED_OPTIONS=	pkgin-prefer-gzip
.endif

.include "../../mk/bsd.options.mk"

.if ${PKG_OPTIONS:Mpkgin-prefer-gzip}
CPPFLAGS+=	-DPREFER_GZIP_SUMMARY
.endif

#
# Link pkgsrc libraries statically where possible, avoiding a large number of
# potential upgrade issues.  This is a bit hacky and OS-specific so is not
# enabled by default, but has been proven by large installations to work well.
#
.if ${PKG_OPTIONS:Mpkgin-static}
# All implicit dependents of the main shared libraries need to be added.
LIBS.Darwin+=	-lbz2 -liconv -llzma -lz
LIBS.SunOS+=	-lbz2 -llzma -lm -lnsl -lz

.  for dep in libarchive sqlite3 libfetch openssl
BUILDLINK_DEPMETHOD.${dep}=	build
.  endfor

pre-configure:
	${RM} -f ${BUILDLINK_DIR}/lib/*.dylib
	${RM} -f ${BUILDLINK_DIR}/lib/*.so*
.endif
