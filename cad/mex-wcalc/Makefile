# $NetBSD: Makefile,v 1.3 2005/12/05 20:49:52 rillig Exp $
#

.include "../../cad/wcalc/Makefile.common"
PKGNAME=	mex-${DISTNAME}

COMMENT=	Matlab Based Transmission Line Analysis/Synthesis Calculator

# Only enable the matlab frontend
CONFIGURE_ARGS+=	--disable-cgi
CONFIGURE_ARGS+=	--disable-gtk1
CONFIGURE_ARGS+=	--disable-gtk2
CONFIGURE_ARGS+=	--disable-htdocs
CONFIGURE_ARGS+=	--disable-libwcalc
CONFIGURE_ARGS+=	--disable-stdio
CONFIGURE_ARGS+=	--with-matlab
CONFIGURE_ARGS+=	--without-octave
CONFIGURE_ARGS+=	--without-scilab

post-patch:
	${MV} ${WRKSRC}/mex-wcalc/mexopts.sh.in \
		${WRKSRC}/mex-wcalc/mexopts.sh.in.orig
	${SED} 's;\.\./libwcalc;${BUILDLINK_DIR}/lib;g' \
		${WRKSRC}/mex-wcalc/mexopts.sh.in.orig \
		> ${WRKSRC}/mex-wcalc/mexopts.sh.in

# This depends on an installation of Matlab which pkgsrc does
# not have.  We should find a sane way to deal with this.  It is
# not clear if linux/solaris matlab users care to use pkgsrc
# to manage its installation or if it will always be installed
# outside of pkgsrc.

# In addition, mex-wcalc will not currently build correctly
# if you are using a non-native matlab (i.e. linux or solaris
# matlab on NetBSD).
#
# To get mex-wcalc to work under emulation you need to set up
# a cross-tool chain, build a libwcalc targeted to the same
# system as the matlab installation, and modify the mexopts.sh
# file in ${WRKSRC}/mex-wcalc to use this cross tool chain.
# Basically what it comes down to is you need to compile shared
# modules for the same os as the matlab binary.
#
ONLY_FOR_PLATFORM=	Linux-*-i386 SunOS-*-sparc*

.include "../../mk/bsd.prefs.mk"

_MATLAB_ARCH=	unknown
_MATLAB_MEX=	mex
_MEX_SUFX=	unknown
.if ${OPSYS} == "Linux"
. if (${MACHINE_ARCH} == "i386")
_MATLAB_ARCH=	glnx86
_MEX_SUFX=	mexglx
. endif
.elif ${OPSYS} == "SunOS"
. if (${MACHINE_ARCH} == "sparc")
_MATLAB_ARCH=	sol2
_MEX_SUFX=	mexsol
. endif
.endif
MATLAB_ARCH?=	${_MATLAB_ARCH}
MEX_SUFX?=	${_MEX_SUFX}

MATLAB_MEX?=		${_MATLAB_MEX}

PLIST_SUBST+=		MEX_SUFX=${MEX_SUFX:Q}

.if !empty(PHASES_AFTER_EXTRACT:M${PKG_PHASE})
MATLAB_DIR!=		${MATLAB_MEX} -v 2>/dev/null | ${AWK} '/[ \t]MATLAB[ \t]/ {print $$NF}'

BUILDLINK_PASSTHRU_DIRS+=	${MATLAB_DIR}/extern/include
BUILDLINK_PASSTHRU_DIRS+=	${MATLAB_DIR}/simulink/include
BUILDLINK_PASSTHRU_DIRS+=	${MATLAB_DIR}/bin/${MATLAB_ARCH}
.endif

.include "../../cad/libwcalc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
