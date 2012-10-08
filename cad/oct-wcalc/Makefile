# $NetBSD: Makefile,v 1.11 2012/10/08 13:25:14 asau Exp $
#

.include "../../cad/wcalc/Makefile.common"
PKGNAME=	oct-${DISTNAME}
PKGREVISION=	5

COMMENT=	Octave Based Transmission Line Analysis/Synthesis Calculator

# Only enable the octave frontend
CONFIGURE_ARGS+=	--disable-cgi
CONFIGURE_ARGS+=	--disable-gtk1
CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--disable-htdocs
CONFIGURE_ARGS+=	--disable-libwcalc
CONFIGURE_ARGS+=	--disable-stdio
CONFIGURE_ARGS+=	--without-matlab
CONFIGURE_ARGS+=	--with-octave
CONFIGURE_ARGS+=	--without-scilab

# This mirrors what octave-current/octave-forge use.
# The c++ code is from the mex wrappers created by
# the octave-forge mex script, not any c++ code
# explicitly present in wcalc.  The fortran part
# also comes from ocatve, not from wcalc.
GCC_REQD+=	3.0
USE_LANGUAGES=	c c++ fortran77

.include "../../math/octave/octave.mk"

PLIST_SUBST+=	OCT_LOCALVERFCNFILEDIR=${OCT_LOCALVERFCNFILEDIR:S/${LOCALBASE}\///}
PLIST_SUBST+=	OCT_LOCALVEROCTFILEDIR=${OCT_LOCALVEROCTFILEDIR:S/${LOCALBASE}\///}

.include "../../cad/libwcalc/buildlink3.mk"
.include "../../math/octave/buildlink3.mk"
.include "../../math/octave-forge/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
