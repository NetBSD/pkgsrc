# $NetBSD: Makefile,v 1.42 2024/05/06 08:33:51 jperkin Exp $

DISTNAME=		gpc-2.1
PKGREVISION=		5
CATEGORIES=		lang
MASTER_SITES=		http://www.gnu-pascal.de/stable/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		gcc-2.95.3.tar.gz
SITES.gcc-2.95.3.tar.gz= ${MASTER_SITE_GNU:=gcc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu-pascal.de/gpc/h-index.html
COMMENT=		GNU Pascal Compiler

PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCHFILES=		gcc-2.95.3-diff-2002-08-29.gz

NOT_FOR_PLATFORM+=	Darwin-*-* Interix-*-* *-*-x86_64 *-*-aarch64

WRKSRC=			${WRKDIR}/gcc-2.95.3
USE_TOOLS+=		gmake gsed
PLIST_SRC=		PLIST

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CFLAGS+=		-DNETBSD_NATIVE
GPC_PREFIX=		${PREFIX}
GPC_SUBPREFIX=
PLIST_SRC+=		PLIST.netbsd
.else
GPC_PREFIX=		${_GCC_PREFIX}
GPC_SUBPREFIX=		${_GCC_SUBPREFIX}/
.endif

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	${WRKSRC}/configure
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM:Q}
CONFIGURE_ARGS+=	--prefix=${GPC_PREFIX:Q}
CONFIGURE_ARGS+=	--infodir=${PREFIX:Q}/${PKGINFODIR:Q}
CONFIGURE_ARGS+=	--mandir=${PREFIX:Q}/${PKGMANDIR:Q}
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--enable-languages=pascal

PLIST_SUBST+=		GPC_SUBPREFIX=${GPC_SUBPREFIX:Q}

CONFIGURE_DIRS=		${WRKDIR}/objdir
BUILD_DIRS=		${CONFIGURE_DIRS}
INSTALL_DIRS=		${BUILD_DIRS}/gcc

INSTALL_TARGET=		pascal.install

INFO_FILES=	yes

post-extract:
	${MKDIR} ${WRKSRC}
	${CP} ../../lang/gcc2/files/xm-netbsd.h ${WRKSRC}/gcc/config
	${CP} ../../lang/gcc2/files/xm-target64.h ${WRKSRC}/gcc/config
	for file in ../../lang/gcc2/files/*_* ; do			 \
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
