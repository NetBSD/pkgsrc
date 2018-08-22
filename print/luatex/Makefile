# $NetBSD: Makefile,v 1.75 2018/08/22 09:46:14 wiz Exp $

DISTNAME=	texlive-20180414-source
PKGNAME=	luatex-1.07.0
PKGREVISION=	4
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2018/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.luatex.org/
COMMENT=	Extended version of pdfTeX using Lua
LICENSE=	gnu-gpl-v2

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/libs/lua52 \
			${DISTNAME}/libs/luajit \
			${DISTNAME}/texk/web2c

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c99 c++11
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake gsed lex perl pkg-config yacc
CONFIGURE_ARGS+=	--disable-aleph --disable-etex --disable-pdftex \
			--enable-luatex --disable-mf --disable-mf-nowin \
			--with-x=no \
			--disable-luatex53 --disable-luajittex --disable-mfluajit \
			--disable-mp --disable-pmp --disable-upmp \
			--disable-ptex --disable-eptex --disable-uptex --disable-euptex \
			--disable-web-progs \
			--enable-web2c --disable-xetex
CONFIGURE_ARGS+=	--with-system-poppler
CONFIGURE_ARGS+= \
	--with-fontconfig-includes=${BUILDLINK_PREFIX.fontconfig}/include \
	--with-fontconfig-libdir=${BUILDLINK_PREFIX.fontconfig}/lib
CONFIGURE_ARGS+=	--with-system-kpathsea
CONFIGURE_ARGS+=	--with-system-zlib \
	--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include \
	--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-system-cairo
CONFIGURE_ARGS+=	--with-system-pixman
CONFIGURE_ARGS+=	--with-system-libpng
CONFIGURE_ARGS+=	--with-system-freetype2
CONFIGURE_ARGS+=	--with-system-zziplib
CONFIGURE_ARGS+=	--with-system-mpfr \
			--with-mpfr-includes=${BUILDLINK_PREFIX.mpfr}/include \
			--with-mpfr-libdir=${BUILDLINK_PREFIX.mpfr}/lib
CONFIGURE_ARGS+=	--with-system-gmp \
			--with-gmp-includes=${BUILDLINK_PREFIX.gmp}/include \
			--with-gmp-libdir=${BUILDLINK_PREFIX.gmp}/lib

CONFIGURE_DIRS=		libs/lua52
CONFIGURE_DIRS+=	texk/web2c

INSTALLATION_DIRS+=	bin lib

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-configure
SUBST_FILES.prefix=	libs/lua52/lua52-src/src/luaconf.h
SUBST_VARS.prefix=	PREFIX

CPPFLAGS.SunOS+=	-D_XOPEN_SOURCE_EXTENDED=0

.include "../../archivers/zziplib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"

pre-configure:
	# Ensure we generate our patched version
	${RM} -f libs/luajit/lj_vm_asm.S

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} ${WRKSRC}/libs/lua52/libtexlua52.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/texk/web2c/luatex ${DESTDIR}${PREFIX}/bin
.for f in texlua texluac
	${LN} -s luatex ${DESTDIR}${PREFIX}/bin/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
