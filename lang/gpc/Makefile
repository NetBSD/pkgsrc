# $NetBSD: Makefile,v 1.13 2003/09/17 19:40:41 grant Exp $

DISTNAME=		gpc-2.1
PKGREVISION=		3
WRKSRC=			${WRKDIR}/gcc-2.95.3
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITES+=		http://www.gnu-pascal.de/current/ \
			${MASTER_SITE_GNU:=gcc/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		gcc-2.95.3.tar.gz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu-pascal.de
COMMENT=		GNU Pascal Compiler

PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		gcc-2.95.3-diff-2002-08-29.gz

BUILD_DEPENDS+=		gsed-[0-9]*:../../textproc/gsed

USE_BUILDLINK2=		# defined
USE_GMAKE=		# defined
USE_NCURSES=		# defined
PLIST_SRC=		PLIST

.include "../../mk/bsd.prefs.mk"

GCC_REQD=		2.95.3

.if ${OPSYS} == "NetBSD"
CFLAGS+=		-DNETBSD_NATIVE
GPC_PREFIX=		${PREFIX}
GPC_SUBPREFIX=
PLIST_SRC+=		PLIST.netbsd
.else
GPC_PREFIX=		${_GCC_PREFIX}
GPC_SUBPREFIX=		${_GCC_SUBPREFIX}/
.endif

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

.include "../../mk/bsd.pkg.mk"
