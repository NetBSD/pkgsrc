# $NetBSD: Makefile,v 1.2 2004/07/23 13:03:56 xtraeme Exp $
#

DISTNAME=	wimon-0.3
CATEGORIES=	net
MASTER_SITES=	http://imil.net/wimon/

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://imil.net/wimon/
COMMENT=	Tool that shows a real-time graph of your wireless connection

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ONLY_FOR_PLATFORM=      FreeBSD-*-* NetBSD-*-* OpenBSD-*-*

WRKSRC=		${WRKDIR}/wimon
USE_BUILDLINK3=	yes

INSTALLATION_DIRS=	bin man/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wimon ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wimon.8 ${PREFIX}/man/man8

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
