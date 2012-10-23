# $NetBSD: Makefile,v 1.14 2012/10/23 17:18:59 asau Exp $
#

DISTNAME=	poink-1.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Nosuid, absolutely secure version of ping utility

NO_SRC_ON_FTP=	Already in MASTER_SITE_LOCAL.

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/poink ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ping.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/poink.1

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
