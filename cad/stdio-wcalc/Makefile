# $NetBSD: Makefile,v 1.2 2006/01/08 06:31:54 dmcmahill Exp $
#

.include "../../cad/wcalc/Makefile.common"
PKGNAME=	stdio-${DISTNAME}

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
