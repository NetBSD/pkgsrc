# $NetBSD: Makefile,v 1.7 2003/08/21 18:28:17 drochner Exp $
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
# A gcc tree with compiler driver and gnatbind should be in ADA_BOOT_PATH.
#ADA_BOOT_PATH=		/path/to/adagcc
# Use this if a special compiler driver is needed to compile ada programs
# (as seen in linux installations).
#GNATGCC_ADA_DRIVER=	gnatgcc

.if defined(ADA_BOOT_PATH)

.if defined(GNATGCC_ADA_DRIVER)
ADA_BOOT_ADAC=	${ADA_BOOT_PATH}/bin/${GNATGCC_ADA_DRIVER}
.else
ADA_BOOT_ADAC=	${ADA_BOOT_PATH}/bin/gcc
.endif

ADA_BOOT_GNATBIND=	${ADA_BOOT_PATH}/bin/gnatbind

EXTRA_ENV+=	ADAC=${ADA_BOOT_ADAC:Q}
CONFIGURE_ENV+=	${EXTRA_ENV}
MAKE_ENV+=	${EXTRA_ENV}

.else # !ADA_BOOT_PATH

# XXX No known system has ada in the main tree.
ONLY_FOR_PLATFORM=	sorry_need_ada_compiler

.endif # ADA_BOOT_PATH

#
# End of bootstrap section
#

post-buildlink:
	${LN} -sf ${ADA_BOOT_GNATBIND} ${BUILDLINK_DIR}/bin

post-configure:
	${TEST} -f ${WRKSRC}/gcc/ada/Makefile \
	  || ${FALSE} # no ada bootstrap found by configure
	(cd ${WRKSRC}/gcc/ada && ${TOUCH} treeprs.ads [es]info.h nmake.ad[bs])

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
