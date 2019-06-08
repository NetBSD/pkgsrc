# $NetBSD: Makefile,v 1.12 2019/06/08 11:04:29 rillig Exp $
#

.include "../../cad/wcalc/Makefile.common"
PKGNAME=	mex-${DISTNAME}
PKGREVISION=	2

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

SUBST_CLASSES+=		mwc
SUBST_STAGE.mwc=	pre-configure
SUBST_FILES.mwc=	mex-wcalc/mexopts.sh.in
SUBST_SED.mwc=		-e 's;\.\./libwcalc;${BUILDLINK_DIR}/lib;g'

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

DEF_MATLAB_ARCH=	unknown
DEF_MATLAB_MEX=		mex
DEF_MEX_SUFX=		unknown
.if ${OPSYS} == "Linux"
.  if (${MACHINE_ARCH} == "i386")
DEF_MATLAB_ARCH=	glnx86
DEF_MEX_SUFX=		mexglx
.  endif
.elif ${OPSYS} == "SunOS"
.  if (${MACHINE_ARCH} == "sparc")
DEF_MATLAB_ARCH=	sol2
DEF_MEX_SUFX=		mexsol
.  endif
.endif
MATLAB_ARCH?=		${DEF_MATLAB_ARCH}
MEX_SUFX?=		${DEF_MEX_SUFX}

MATLAB_MEX?=		${DEF_MATLAB_MEX}

PLIST_SUBST+=		MEX_SUFX=${MEX_SUFX:Q}

.if !defined(MATLAB_DIR)
MATLAB_DIR!=								\
	case ${MATLAB_MEX:Q}"" in					\
	/*)	matlab_mex=${MATLAB_MEX:Q} ;;				\
	*)	SAVEIFS="$$IFS"; IFS=:;					\
		for p in $$PATH; do					\
			${TEST} ! -x $$p/${MATLAB_MEX} ||		\
				matlab_mex=$$p/${MATLAB_MEX};		\
		done;							\
		IFS="$$SAVEIFS";					\
		;;							\
	esac;								\
	if ${TEST} -z "$$matlab_mex"; then				\
		${ECHO} "MATLAB_DIR_not_set";				\
	else								\
		$$matlab_mex -v 2>/dev/null |				\
		${AWK} 'BEGIN { s = "MATLAB_DIR_not_set" }		\
			/[ \t]MATLAB[ \t]/ { s = $$NF }			\
			END { print s }';				\
	fi
.  if empty(MATLAB_DIR:M*not_set)
MAKEVARS+=	MATLAB_DIR
.  endif
.endif

BUILDLINK_PASSTHRU_DIRS+=	${MATLAB_DIR}/extern/include
BUILDLINK_PASSTHRU_DIRS+=	${MATLAB_DIR}/simulink/include
BUILDLINK_PASSTHRU_DIRS+=	${MATLAB_DIR}/bin/${MATLAB_ARCH}

.include "../../cad/libwcalc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
