# $NetBSD: Makefile,v 1.6 2003/08/11 14:15:58 drochner Exp $
#

PKGNAME=		gcc3${GCC3_PKGMODIF}-ada-${GCC_VERSION}
COMMENT=		GNU Compiler Collection, version 3, Ada compiler

INFO_FILES=	gnat_ug_unx.info gnat_ug_vms.info gnat_ug_vxw.info
INFO_FILES+=	gnat_ug_wnt.info gnat_rm.info gnat-style.info

.include "../../lang/gcc3-c/buildaddon.mk"

CONFIGURE_ARGS+=	--enable-languages="ada"

#
# Bootstrap section. Define something to make the pkg usable.
#
# To make things more interesting, we need a gcc with ada support to build
# ada support.
# The ADA_BOOT definition is used if the system compiler is not sufficient.
# For pkg bootstrap, the ada capable gcc (probably cross-compiled)
# can be anywhere.
# GNATGCC_PREFIX assumes a standard gcc install tree layout.
#GNATGCC_PREFIX=	/usr/pkg/gcc3

# Use this if a special compiler driver is needed to compile ada programs
# (as seen in linux installations).
#GNATGCC_ADA_DRIVER=	gnatgcc

.if defined(GNATGCC_PREFIX)
ADA_BOOT=	yes
ADA_BOOT_CC=	${GNATGCC_PREFIX}/bin/gcc
ADA_BOOT_CPP=	${GNATGCC_PREFIX}/bin/gcc -E
.if defined(GNATGCC_ADA_DRIVER)
ADA_BOOT_ADAC=	${GNATGCC_PREFIX}/bin/${GNATGCC_ADA_DRIVER}
.else
ADA_BOOT_ADAC=	${GNATGCC_PREFIX}/bin/gcc
.endif
ADA_BOOT_PATH=	${GNATGCC_PREFIX}/bin
.endif

.if defined(ADA_BOOT)

# probably some overkill here...

CC=		${ADA_BOOT_CC}
CPP=		${ADA_BOOT_CPP}
PATH:=		${ADA_BOOT_PATH}:${PATH}

EXTRA_ENV=	CC=${ADA_BOOT_CC:Q}
EXTRA_ENV=	CC_FOR_BUILD=${ADA_BOOT_CC:Q}
EXTRA_ENV+=	CPP=${ADA_BOOT_CPP:Q}
EXTRA_ENV+=	ADAC=${ADA_BOOT_ADAC:Q}
EXTRA_ENV+=	PATH=${ADA_BOOT_PATH}:${PATH}

CONFIGURE_ENV+=	${EXTRA_ENV}
MAKE_ENV+=	${EXTRA_ENV}

.else # !ADA_BOOT

# XXX No known system has ada in the main tree.
ONLY_FOR_PLATFORM=	sorry_need_ada_compiler

.endif # ADA_BOOT

#
# End of bootstrap section
#

post-configure:
	${TEST} -f ${WRKSRC}/gcc/ada/Makefile \
	  || ${FALSE} # no ada bootstrap found by configure
.if defined(ADA_BOOT) # ??? see install notes
	(cd ${WRKSRC}/gcc/ada && ${TOUCH} treeprs.ads [es]info.h nmake.ad[bs])
.endif

do-build:
	(cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} ada)
	# XXX avoid some VPATH related lossage
	(cd ${WRKSRC}/gcc/ada && ${MV} targtyps.o targtyps.o.sav)
	(cd ${WRKSRC}/gcc/ada && ${RM} -f *.o *.ali)
	(cd ${WRKSRC}/gcc/ada && ${MV} targtyps.o.sav targtyps.o)
	(cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} gnatlib_and_tools)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/gnat1 ${GCC_ARCHDIR}
	(cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		ada.install-common ada.install-info install-gnatlib)
	${RM} -f ${GCC_ARCHDIR}/adalib/lib*.so

.include "../../mk/bsd.pkg.mk"
