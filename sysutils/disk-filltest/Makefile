# $NetBSD: Makefile,v 1.3 2025/01/11 06:39:48 scole Exp $

DISTNAME=	disk-filltest-0.8.2
CATEGORIES=	sysutils
MASTER_SITES=	https://panthema.net/2013/disk-filltest/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://panthema.net/2013/disk-filltest/
COMMENT=	Detect Bad Disks by Filling with Random Data
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=	bin share/doc/disk-filltest ${PKGMANDIR}/man1

BUILD_TARGET=	disk-filltest

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/disk-filltest ${DESTDIR}${PREFIX}/bin/disk-filltest
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/disk-filltest/README
	${INSTALL_MAN} ${WRKSRC}/disk-filltest.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
