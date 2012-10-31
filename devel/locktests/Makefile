# $NetBSD: Makefile,v 1.2 2012/10/31 11:17:25 asau Exp $
#

DISTNAME=	locktests
PKGNAME=	${DISTNAME}-20110428
CATEGORIES=	devel filesystems
MASTER_SITES=	http://nfsv4.bullopensource.org/tools/tests_tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nfsv4.bullopensource.org/tools/tests_tools/
COMMENT=	POSIX locks stress-test
LICENSE=	gnu-gpl-v3 # According to web site

WRKSRC=	${WRKDIR}/locks
BUILD_TARGET=	All

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/locktests ${DESTDIR}${PREFIX}/bin/locktests

.include "../../mk/bsd.pkg.mk"
