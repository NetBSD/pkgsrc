# $NetBSD: Makefile,v 1.1.1.1 2003/02/17 18:47:15 jtb Exp $

DISTNAME=		gpc-2.1
CATEGORIES=		lang
MASTER_SITES=		http://www.gnu-pascal.de/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		gcc-2.95.3.tar.gz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu-pascal.de
COMMENT=		GNU Pascal Compiler

PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		gcc-2.95.3-diff-2002-08-29.gz

DEPENDS+=		gmp-[0-9]*:../../devel/gmp
DEPENDS+=		ncurses-[0-9]*:../../devel/ncurses
DEPENDS+=		rx-[0-9]*:../../devel/rx

BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
BUILD_DEPENDS+=		gsed-[0-9]*:../../textproc/gsed

WRKSRC=			${WRKDIR}/gcc-2.95.3
USE_GMAKE=		# defined
USE_NCURSES=		# defined
USE_PKGSRC_GCC=		# defined

GPC_PREFIX=		${_GCC_PREFIX}
GPC_SUBPREFIX=		${_GCC_SUBPREFIX}

HAS_CONFIGURE=		# defined
CONFIGURE_SCRIPT=	${WRKSRC}/configure
CONFIGURE_ARGS=		--host=${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--prefix=${GPC_PREFIX}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/info
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-languages=pascal

PLIST_SUBST+=		GPC_SUBPREFIX=${GPC_SUBPREFIX}

CONFIGURE_DIRS=		${WRKDIR}/objdir
BUILD_DIRS=		${CONFIGURE_DIRS}
INSTALL_DIRS=		${BUILD_DIRS}/gcc

INSTALL_TARGET=		pascal.install

INFO_FILES=		gpc.info gpcs.info

.include "../../mk/bsd.prefs.mk"

post-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${.CURDIR}/../gcc/files/xm-netbsd.h ${WRKSRC}/gcc/config
	${CP} ${.CURDIR}/../gcc/files/xm-target64.h ${WRKSRC}/gcc/config
	for file in ${.CURDIR}/../gcc/files/*_* ; do			 \
		arch=`${BASENAME} $${file} | ${SED} -e "s/_.*//"`;	 \
		dest=`${BASENAME} $${file} | ${SED} -e "s/$${arch}_//"`; \
		${MKDIR} ${WRKSRC}/gcc/config/$${arch};			 \
		${CP} $${file} ${WRKSRC}/gcc/config/$${arch}/$${dest};	 \
	done
	${RM} ${WRKSRC}/gcc/config/alpha/netbsd-elf.h
	${RM} ${WRKSRC}/gcc/config/arm/t-netbsd
	${RM} ${WRKSRC}/gcc/config/mips/x-netbsd

pre-patch:
	${MV} -f ${WRKDIR}/gpc-20020510/p ${WRKDIR}/gcc-2.95.3/gcc/

pre-configure:
	${MKDIR} ${BUILD_DIRS}
	${TOUCH} ${TOUCH_FLAGS}	${WRKSRC}/gcc/c-gperf.h
	${ECHO} "bogus" > ${WRKSRC}/gcc/cstamp-h.in

.include "../../lang/gcc/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
