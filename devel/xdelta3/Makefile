# $NetBSD: Makefile,v 1.6 2010/03/15 12:22:24 wiz Exp $
#

DISTNAME=		xdelta3.0y
PKGNAME=		xdelta3-3.0y
CATEGORIES=		devel
MASTER_SITES=		http://xdelta.googlecode.com/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xdelta.org/
COMMENT=		Enhanced diff that works on binary files (version 3.x)
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_TARGET=		xdelta3
USE_TOOLS+=		gmake
INSTALLATION_DIRS=	bin share/doc/xdelta3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdelta3 ${DESTDIR}${PREFIX}/bin/xdelta3
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xdelta3

do-test:
	${WRKSRC}/xdelta3 test

.include "../../mk/bsd.pkg.mk"
