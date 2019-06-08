# $NetBSD: Makefile,v 1.7 2019/06/08 11:04:29 rillig Exp $
#

.include "../../cad/wcalc/Makefile.common"
PKGNAME=	lib${DISTNAME}
PKGREVISION=	2

COMMENT=	Library for Transmission Line Analysis/Synthesis

# Disable all the frontends so we only build/install the libwcalc
# portion
CONFIGURE_ARGS+=	--disable-cgi
CONFIGURE_ARGS+=	--disable-gtk1
CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--disable-htdocs
CONFIGURE_ARGS+=	--enable-libwcalc
CONFIGURE_ARGS+=	--disable-stdio
CONFIGURE_ARGS+=	--without-matlab
CONFIGURE_ARGS+=	--without-octave
CONFIGURE_ARGS+=	--without-scilab

USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE=	libwcalc/wcalc.pc.in

BUILD_DIRS=		. po

pre-build:
	${MV} ${WRKSRC}/libwcalc/wcalc-config ${WRKSRC}/libwcalc/wcalc-config.bak
	${SED} 's;^RPATH.*;RPATH_FLAG="${COMPILER_RPATH_FLAG}";g' ${WRKSRC}/libwcalc/wcalc-config.bak > \
		${WRKSRC}/libwcalc/wcalc-config
	${CHMOD} 755 ${WRKSRC}/libwcalc/wcalc-config

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
