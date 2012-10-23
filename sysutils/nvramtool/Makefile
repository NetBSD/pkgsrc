# $NetBSD: Makefile,v 1.4 2012/10/23 19:51:15 asau Exp $
#

DISTNAME=	nvramtool-r6338
PKGNAME=	nvramtool-0pre6338
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL:=nvramtool/}

MAINTAINER=	jakllsch@kollasch.net
HOMEPAGE=	http://www.coreboot.org/Nvramtool
COMMENT=	Coreboot CMOS NVRAM manipulation utility
LICENSE=	gnu-gpl-v2

USE_TOOLS+= gmake
USE_TOOLS+= date

USE_LANGUAGES+= c

.include "../../mk/bsd.prefs.mk"

ONLY_FOR_PLATFORM=	#Darwin-*-i386 Darwin*-x86_64 # would need DirectIO
ONLY_FOR_PLATFORM+=	FreeBSD-*-i386 FreeBSD-*-x86_64
ONLY_FOR_PLATFORM+=	Linux-*-i386 Linux-*-x86_64
ONLY_FOR_PLATFORM+=	NetBSD-*-i386 NetBSD-*-x86_64

WRKSRC=			${WRKDIR}/${PKGBASE}

BUILD_TARGET= nvramtool

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nvramtool ${DESTDIR}${PREFIX}/sbin/nvramtool
	${INSTALL_MAN} ${WRKSRC}/cli/nvramtool.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/nvramtool.8

.include "../../mk/bsd.pkg.mk"
