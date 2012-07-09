# $NetBSD: Makefile,v 1.10 2012/07/09 01:51:34 minskim Exp $

DISTNAME=	texlive-20110705-source
PKGNAME=	xetex-0.9997.5
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.tug.org/xetex/
COMMENT=	TeX system with Unicode and modern font technologies

CONFLICTS+=	web2c<=7.5.7
DEPENDS+=	xdvipdfmx-[0-9]*:../../print/xdvipdfmx

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/libs/graphite ${DISTNAME}/libs/icu \
			${DISTNAME}/libs/xpdf ${DISTNAME}/libs/obsdcompat \
			${DISTNAME}/texk/web2c

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake lex perl pkg-config yacc
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c

CONFIGURE_ARGS+=	--disable-aleph --disable-etex --disable-pdftex \
			--disable-luatex --disable-mf --disable-mf-nowin \
			--disable-mp --disable-ptex --disable-eptex \
			--disable-web-progs \
			--enable-web2c --enable-xetex
CONFIGURE_ARGS+= \
	--with-fontconfig-includes=${BUILDLINK_PREFIX.fontconfig}/include \
	--with-fontconfig-libdir=${BUILDLINK_PREFIX.fontconfig}/lib
CONFIGURE_ARGS+=	--with-system-kpathsea \
	--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
	--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib
CONFIGURE_ARGS+=	--with-system-zlib \
	--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include \
	--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-system-libpng \
	--with-libpng-includes=${BUILDLINK_PREFIX.libpng}/include \
	--with-libpng-libdir=${BUILDLINK_PREFIX.libpng}/lib
CONFIGURE_ARGS+=	--with-system-freetype2
CONFIGURE_ARGS+=	--with-system-teckit \
	--with-teckit-includes=${BUILDLINK_PREFIX.TECkit}/include/teckit \
	--with-teckit-libdir=${BUILDLINK_PREFIX.TECkit}/lib

CONFIGURE_DIRS=	${WRKDIR}/${DISTNAME}/libs/graphite \
		${WRKDIR}/${DISTNAME}/libs/icu \
		${WRKDIR}/${DISTNAME}/libs/xpdf \
		${WRKDIR}/${DISTNAME}/libs/obsdcompat \
		${WRKDIR}/${DISTNAME}/texk/web2c

EVAL_PREFIX+=	XDVIPDFMX_PREFIX=xdvipdfmx

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	xetexdir/XeTeX_ext.c
SUBST_SED.paths=	-e 's,@XDVIPDFMX@,${XDVIPDFMX_PREFIX}/bin/xdvipdfmx,g'

INSTALLATION_DIRS+=	bin

.include "../../mk/bsd.prefs.mk"

# ATSUI is deprecated in Mac OS X Snow Leopard
.if !empty(MACHINE_PLATFORM:MDarwin-1[0-9]*)
CONFIGURE_ENV+=	kpse_cv_have_Carbon=no
.endif

.include "../../converters/TECkit/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xetex ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
