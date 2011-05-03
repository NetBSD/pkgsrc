# $NetBSD: Makefile,v 1.1.1.1 2011/05/03 12:32:40 manu Exp $
#

DISTNAME=	locktests
PKGNAME=	${DISTNAME}-20110428
CATEGORIES=	devel filesystems
MASTER_SITES=	http://nfsv4.bullopensource.org/tools/tests_tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nfsv4.bullopensource.org/tools/tests_tools/
COMMENT=	POSIX locks stress-test
LICENSE=	gnu-gpl-v3 # According to web site

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/locks
BUILD_TARGET=	All

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/locktests ${DESTDIR}${PREFIX}/bin/locktests

.include "../../mk/bsd.pkg.mk"
