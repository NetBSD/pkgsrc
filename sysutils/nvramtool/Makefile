# $NetBSD: Makefile,v 1.1.1.1 2011/02/08 16:51:17 jakllsch Exp $
#

DISTNAME=	nvramtool-r6338
PKGNAME=	nvramtool-0pre6338
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL:=${PKGNAME_NOREV}/}

MAINTAINER=	jakllsch@kollasch.net
HOMEPAGE=	http://www.coreboot.org/Nvramtool
COMMENT=	Coreboot CMOS NVRAM manipulation utility
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+= gmake
USE_TOOLS+= date

USE_LANGUAGES+= c

.include "../../mk/bsd.prefs.mk"

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64
ONLY_FOR_PLATFORM+=     Linux-*-i386 Linux-*-x86_64 # not yet tested.

WRKSRC=			${WRKDIR}/${PKGBASE}

BUILD_TARGET= nvramtool

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nvramtool ${DESTDIR}${PREFIX}/sbin/nvramtool
	${INSTALL_MAN} ${WRKSRC}/cli/nvramtool.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/nvramtool.8

.include "../../mk/bsd.pkg.mk"
