# $NetBSD: Makefile,v 1.4 2012/10/23 19:51:15 asau Exp $
#

DISTNAME=		oak-1.5.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.ktools.org/dist/oak/

MAINTAINER=		jdw-pkgsrc@menelos.com
HOMEPAGE=		http://www.ktools.org/dist/oak/
COMMENT=		System log reporting tool

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
BUILD_TARGET=

RCD_SCRIPTS=		oak
CONF_FILES=		${PREFIX}/share/examples/oak/oak.conf ${PKG_SYSCONFDIR}/oak.conf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/oak

post-install:
	${INSTALL_DATA}	${FILESDIR}/oak.conf* ${DESTDIR}${PREFIX}/share/examples/oak/
	${INSTALL_DATA} ${FILESDIR}/oak.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
