# $NetBSD: Makefile,v 1.2 2020/01/26 17:32:09 rillig Exp $

DISTNAME=	disk-filltest-0.7.1
CATEGORIES=	sysutils
MASTER_SITES=	http://panthema.net/2013/disk-filltest/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://panthema.net/2013/disk-filltest/
COMMENT=	Detect Bad Disks by Filling with Random Data
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=	bin share/doc/disk-filltest

BUILD_TARGET=	disk-filltest

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/disk-filltest ${DESTDIR}${PREFIX}/bin/disk-filltest
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/disk-filltest/README

.include "../../mk/bsd.pkg.mk"
