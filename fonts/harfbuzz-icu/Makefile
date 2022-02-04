# $NetBSD: Makefile,v 1.8 2022/02/04 16:39:36 ryoon Exp $

# XXX: hack to override meson installation
INSTALL_DIRS=

.include "../../fonts/harfbuzz/Makefile.common"

PKGNAME=	${DISTNAME:S/^harfbuzz-/harfbuzz-icu-/1}

COMMENT=	OpenType text shaping engine (ICU integration)

MESON_ARGS+=	-Dicu=enabled

INSTALLATION_DIRS+=	include/harfbuzz
INSTALLATION_DIRS+=	lib
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
HARFBUZZ_ICU_LIBNAME=	libharfbuzz-icu.0.dylib
.else
HARFBUZZ_ICU_LIBNAME=	libharfbuzz-icu.so.0.*[0-9]
.endif

.PHONY: harfbuzz-icu-install

harfbuzz-icu-install:
	${INSTALL_DATA} ${WRKSRC}/src/hb-icu.h \
	    ${DESTDIR}${PREFIX}/include/harfbuzz/hb-icu.h
	${INSTALL_DATA} ${WRKSRC}/output/meson-private/harfbuzz-icu.pc \
	    ${DESTDIR}${PREFIX}/lib/pkgconfig/harfbuzz-icu.pc
	${INSTALL_LIB} ${WRKSRC}/output/src/${HARFBUZZ_ICU_LIBNAME} \
	    ${DESTDIR}${PREFIX}/lib
.if ${OPSYS} == "Darwin"
	cd ${DESTDIR}${PREFIX}/lib && \
	install_name_tool -change @rpath/libharfbuzz.0.dylib ${PREFIX}/lib/libharfbuzz.0.dylib \
		-id ${PREFIX}/lib/${HARFBUZZ_ICU_LIBNAME} ${HARFBUZZ_ICU_LIBNAME} && \
	${LN} -f -s ${HARFBUZZ_ICU_LIBNAME} libharfbuzz-icu.dylib
.else
	cd ${DESTDIR}${PREFIX}/lib && \
	${LN} -f -s ${HARFBUZZ_ICU_LIBNAME} libharfbuzz-icu.so.0 && \
	${LN} -f -s ${HARFBUZZ_ICU_LIBNAME} libharfbuzz-icu.so
.endif

do-install: harfbuzz-icu-install

.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
