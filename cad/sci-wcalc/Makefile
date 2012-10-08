# $NetBSD: Makefile,v 1.9 2012/10/08 13:25:16 asau Exp $
#

.include "../../cad/wcalc/Makefile.common"
PKGNAME=	sci-${DISTNAME}
PKGREVISION=	3

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
CONFIGURE_ARGS+=	--with-scilab=${SCI:Q}

PLIST_SUBST+=		SCIVERSION=${SCIVERSION:Q}
MESSAGE_SUBST+=		SCIVERSION=${SCIVERSION:Q}

.include "../../cad/libwcalc/buildlink3.mk"
.include "../../math/scilab/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
