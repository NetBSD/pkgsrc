# $NetBSD: Makefile,v 1.15 2005/06/16 06:58:00 jlam Exp $

PKGNAME=	gcc3${GCC3_PKGMODIF}-ada-${GCC_VERSION}
COMMENT=	GNU Compiler Collection, v3 - Ada compiler

.include "../../lang/gcc3/language.mk"

PTHREAD_OPTS+=		require native
CONFIGURE_ARGS+=	--enable-languages="ada"
CONFIGURE_ARGS+=	--enable-threads=yes

#
# Bootstrap section. Define something to make the package usable.
#
# To make things more interesting, we need an existing GCC with Ada
# support to build Ada support.
#
# A gcc tree with compiler driver and gnatbind should be in ADA_BOOT_PATH.
#
#ADA_BOOT_PATH=		/path/to/adagcc
#
# Use this if a special compiler driver is needed to compile Ada programs
# (as seen in Linux installations).
#
#GNATGCC_ADA_DRIVER=	gnatgcc

.if defined(ADA_BOOT_PATH)
.  if defined(GNATGCC_ADA_DRIVER)
ADA_BOOT_ADAC=	${ADA_BOOT_PATH}/bin/${GNATGCC_ADA_DRIVER}
.  else
ADA_BOOT_ADAC=	${ADA_BOOT_PATH}/bin/gcc
.  endif
ADA_BOOT_GNATBIND=	${ADA_BOOT_PATH}/bin/gnatbind

EXTRA_ENV+=	ADAC=${ADA_BOOT_ADAC:Q}
CONFIGURE_ENV+=	${EXTRA_ENV}
MAKE_ENV+=	${EXTRA_ENV}

.else # !ADA_BOOT_PATH

PKG_SKIP_REASON=	"Sorry, need an Ada compiler"

.endif # ADA_BOOT_PATH

#
# End of bootstrap section
#

post-patch:
	cd ${FILESDIR};							\
	${CP} adasignal.c ${WRKSRC}/gcc/ada;				\
	${CP} ada_lwp_self.c ${WRKSRC}/gcc/ada;				\
	for i in *.adb *.ads ; do					\
		${CP} $$i ${WRKSRC}/gcc/ada;				\
	done

post-wrapper:
	${LN} -sf ${ADA_BOOT_GNATBIND} ${BUILDLINK_DIR}/bin

post-configure:
	${TEST} -f ${WRKSRC}/gcc/ada/Makefile \
		|| ${FALSE} # no ada bootstrap found by configure
	cd ${WRKSRC}/gcc/ada && ${TOUCH} treeprs.ads [es]info.h nmake.ad[bs]

do-build:
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} ada
	# XXX avoid some VPATH related lossage
	cd ${WRKSRC}/gcc/ada && ${MV} targtyps.o targtyps.o.sav
	cd ${WRKSRC}/gcc/ada && ${RM} -f *.o *.ali
	cd ${WRKSRC}/gcc/ada && ${MV} targtyps.o.sav targtyps.o
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} gnatlib_and_tools

post-build:
	@${SED} ${FILES_SUBST_SED} ${FILESDIR}/gcc3.mk > ${WRKDIR}/gcc3.mk
	${ECHO} "ADA_INCLUDE_PATH+=${GCC_ARCHDIR}/adainclude" >> ${WRKDIR}/gcc3.mk

do-install:
	${INSTALL_PROGRAM_DIR} ${GCC_ARCHDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/gcc/gnat1 ${GCC_ARCHDIR}
	cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		ada.install-common ada.install-info install-gnatlib
	${RM} -f ${GCC_ARCHDIR}/adalib/lib*.so

post-install:
	${INSTALL_DATA} ${WRKDIR}/gcc3.mk ${GCC_PREFIX}/mk/ada.mk

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
