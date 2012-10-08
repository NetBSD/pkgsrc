# $NetBSD: Makefile,v 1.6 2012/10/08 13:25:16 asau Exp $
#

.include "../../cad/wcalc/Makefile.common"
PKGNAME=	stdio-${DISTNAME}
PKGREVISION=	2

COMMENT=	Stdio Based Transmission Line Analysis/Synthesis Calculator

# Only enable the stdio frontend
CONFIGURE_ARGS+=	--disable-cgi
CONFIGURE_ARGS+=	--disable-gtk1
CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--disable-htdocs
CONFIGURE_ARGS+=	--disable-libwcalc
CONFIGURE_ARGS+=	--enable-stdio
CONFIGURE_ARGS+=	--without-matlab
CONFIGURE_ARGS+=	--without-octave
CONFIGURE_ARGS+=	--without-scilab

.include "../../cad/libwcalc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
