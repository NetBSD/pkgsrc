# $NetBSD: Makefile,v 1.6 2003/10/18 12:43:00 cjep Exp $
#

DISTNAME=	mksunbootcd-19990513
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/
COMMENT=	Combines filesystems for Sun computers to make bootable CD-ROM images

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mksunbootcd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/mksunbootcd.1 ${PREFIX}/man/man8/mksunbootcd.8
	${INSTALL_MAN} ${WRKSRC}/mksunbootcd.cat1 ${PREFIX}/man/cat8/mksunbootcd.0

.include "../../mk/bsd.pkg.mk"
