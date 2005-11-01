# $NetBSD: Makefile,v 1.1.1.1 2005/11/01 03:55:38 dmcmahill Exp $
#

.include "../../cad/wcalc/Makefile.common"
PKGNAME=	mex-${DISTNAME}

COMMENT=	Matlab Based Transmission Line Analysis/Synthesis Calculator

# Only enable the matlab frontend
CONFIGURE_ARGS+=	--disable-cgi
CONFIGURE_ARGS+=	--disable-gtk
CONFIGURE_ARGS+=	--disable-htdocs
CONFIGURE_ARGS+=	--disable-libwcalc
CONFIGURE_ARGS+=	--disable-stdio
CONFIGURE_ARGS+=	--with-matlab
CONFIGURE_ARGS+=	--without-octave
CONFIGURE_ARGS+=	--without-scilab

# This depends on an installation of Matlab which pkgsrc does
# not have.  Should find a sane way to deal with this.  It is
# not clear if linux/solaris matlab users care to use pkgsrc
# to manage its installation or if it will always be installed
# outside of pkgsrc.

# In addition, mex-wcalc will not currently build correctly
# if you are using a non-native matlab (i.e. linux or solaris
# matlab on NetBSD).  To get it to work, you need to set up
# a cross-tool chain, build a libwcalc targeted to the same
# system as the matlab installation, and modify the mexopts.sh
# file in ${WRKSRC}/mex-wcalc to use this cross tool chain.
# Basically what it comes down to is you need to compile shared
# modules for the same os as the matlab binary.
#
ONLY_FOR_PLATFORM=	Linux-*-i386 SunOS-*-sparc*

.include "../../mk/bsd.pkg.mk"
