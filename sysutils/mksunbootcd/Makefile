# $NetBSD: Makefile,v 1.3 2001/02/17 17:42:16 wiz Exp $
#

DISTNAME=	mksunbootcd-19990513
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.netbsd.org
COMMENT=	combines filesystems for Sun computers to make bootable CD-ROM images

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mksunbootcd ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/mksunbootcd.1 ${PREFIX}/man/man8/mksunbootcd.8
	${INSTALL_MAN} ${WRKSRC}/mksunbootcd.cat1 ${PREFIX}/man/cat8/mksunbootcd.0

.include "../../mk/bsd.pkg.mk"
