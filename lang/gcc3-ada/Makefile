# $NetBSD: Makefile,v 1.2 2003/07/06 12:31:58 grant Exp $
#

DISTNAME=		gcc-3.3
PKGNAME=		gcc3-ada-3.3
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_GNU:=gcc/gcc-3.3/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gcc/gcc.html
COMMENT=		GNU Compiler Collection

NOT_FOR_PLATFORM=	Darwin-*-*

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_GMAKE=		YES

HAS_CONFIGURE=		YES

CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
CONFIGURE_ARGS+=	--prefix=${GCC_PREFIX}
CONFIGURE_ARGS+=	--enable-languages="ada"

# as this is named gcc3, use DISTNAME instead.
FILES_SUBST+=		PKGNAME_NOREV=${DISTNAME} GCC_PREFIX=${GCC_PREFIX}
MESSAGE_SUBST+=		PKGNAME_NOREV=${DISTNAME}

TEXINFO_REQD=	4.2
INFO_FILES=	gnat_ug_unx.info gnat_ug_vms.info gnat_ug_vxw.info
INFO_FILES=	gnat_ug_wnt.info gnat_rm.info gnat-style.info

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" && exists(/usr/include/pthread.h)
GCC_PLATFORM=	${MACHINE_GNU_ARCH}--netbsdelf2.0
PTHREAD_OPTS+=		require native
.include "../../mk/pthread.buildlink2.mk"
CPPFLAGS+=	-I${BUILDLINK_DIR}/include
CFLAGS+=	-I${BUILDLINK_DIR}/include
.else
GCC_PLATFORM=	${MACHINE_GNU_PLATFORM}
.endif
CONFIGURE_ARGS+=	--host=${GCC_PLATFORM}
PLIST_SUBST+=	GCC_PLATFORM=${GCC_PLATFORM}

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--enable-shared
.else
.  if ${OPSYS} == "SunOS"
CONFIGURE_ARGS+=	--enable-shared
.  else
CONFIGURE_ARGS+=	--disable-shared
.  endif
.  if ${CC:M*gcc*} == ""
ALL_TARGET=		bootstrap
.  endif
.endif

GCC_PREFIX=	${PREFIX}/gcc3
GCC_VERSION=	${PKGVERSION:C|nb*||}
GCC_ARCHDIR=	${GCC_PREFIX}/lib/gcc-lib/${GCC_PLATFORM}/${GCC_VERSION}

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

pre-configure:
	${MKDIR} ${BUILD_DIRS}
	cd ${WRKSRC} && contrib/gcc_update --touch

post-configure:
	${LN} -sf ${GCC_PREFIX}/bin/gcc ${WRKSRC}/gcc/xgcc
.if defined(ADA_BOOT) # ??? see install notes
	(cd ${WRKSRC}/gcc/ada && ${TOUCH} treeprs.ads [es]info.h nmake.ad[bs])
.endif

do-build:
	(cd ${WRKSRC}/gcc && ${SETENV} ${MAKE_ENV} ${GMAKE} tconfig.h)
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

.include "../../lang/gcc3-c/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
