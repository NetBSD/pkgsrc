# $NetBSD: Makefile,v 1.2 2000/03/31 13:25:02 dmcmahill Exp $
#

DISTNAME=	mksunbootcd-19990513
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.netbsd.org

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mksunbootcd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/mksunbootcd.1 ${PREFIX}/man/man8/mksunbootcd.8
	${INSTALL_MAN} ${WRKSRC}/mksunbootcd.cat1 ${PREFIX}/man/cat8/mksunbootcd.0

.include "../../mk/bsd.pkg.mk"
