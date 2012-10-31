# $NetBSD: Makefile,v 1.9 2012/10/31 11:19:53 asau Exp $
#

DISTNAME=		xdelta3.0.0
PKGNAME=		xdelta3-3.0za
CATEGORIES=		devel
MASTER_SITES=		http://xdelta.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xdelta.org/
COMMENT=		Enhanced diff that works on binary files (version 3.x)
LICENSE=		gnu-gpl-v2

BUILD_TARGET=		xdelta3
USE_TOOLS+=		gmake
INSTALLATION_DIRS=	bin share/doc/xdelta3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdelta3 ${DESTDIR}${PREFIX}/bin/xdelta3
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xdelta3

do-test:
	${WRKSRC}/xdelta3 test

.include "../../mk/bsd.pkg.mk"
