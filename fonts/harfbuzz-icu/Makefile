# $NetBSD: Makefile,v 1.1 2020/11/06 15:06:49 nia Exp $

# XXX: hack to override meson installation
INSTALL_DIRS=

.include "../../fonts/harfbuzz/Makefile.common"

PKGNAME=	${DISTNAME:S/^harfbuzz-/harfbuzz-icu-/1}

COMMENT=	OpenType text shaping engine (ICU integration)

MESON_ARGS+=	-Dicu=enabled

INSTALLATION_DIRS+=	include/harfbuzz
INSTALLATION_DIRS+=	lib
INSTALLATION_DIRS+=	lib/pkgconfig

HARFBUZZ_ICU_LIBNAME=	libharfbuzz-icu.so.0.20702.0

.PHONY: harfbuzz-icu-install

harfbuzz-icu-install:
	${INSTALL_DATA} ${WRKSRC}/src/hb-icu.h \
	    ${DESTDIR}${PREFIX}/include/harfbuzz/hb-icu.h
	${INSTALL_DATA} ${WRKSRC}/output/meson-private/harfbuzz-icu.pc \
	    ${DESTDIR}${PREFIX}/lib/pkgconfig/harfbuzz-icu.pc
	${INSTALL_LIB} ${WRKSRC}/output/src/${HARFBUZZ_ICU_LIBNAME} \
	    ${DESTDIR}${PREFIX}/lib
	cd ${DESTDIR}${PREFIX}/lib && ${LN} -s ${HARFBUZZ_ICU_LIBNAME} libharfbuzz-icu.so.0
	cd ${DESTDIR}${PREFIX}/lib && ${LN} -s ${HARFBUZZ_ICU_LIBNAME} libharfbuzz-icu.so

do-install: harfbuzz-icu-install

.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
