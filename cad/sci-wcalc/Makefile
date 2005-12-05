# $NetBSD: Makefile,v 1.2 2005/12/05 20:49:52 rillig Exp $
#

.include "../../cad/wcalc/Makefile.common"
PKGNAME=	sci-${DISTNAME}

COMMENT=	Scilab Based Transmission Line Analysis/Synthesis Calculator

# Only enable the scilab frontend
CONFIGURE_ARGS+=	--disable-cgi
CONFIGURE_ARGS+=	--disable-gtk1
CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--disable-htdocs
CONFIGURE_ARGS+=	--disable-libwcalc
CONFIGURE_ARGS+=	--disable-stdio
CONFIGURE_ARGS+=	--without-matlab
CONFIGURE_ARGS+=	--without-octave
CONFIGURE_ARGS+=	--with-scilab=${SCI}

PLIST_SUBST+=		SCIVERSION=${SCIVERSION:Q}
MESSAGE_SUBST+=		SCIVERSION=${SCIVERSION}

.include "../../cad/libwcalc/buildlink3.mk"
.include "../../math/scilab/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
