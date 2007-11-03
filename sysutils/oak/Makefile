# $NetBSD: Makefile,v 1.1.1.1 2007/11/03 14:28:21 rillig Exp $
#

DISTNAME=		oak-1.5.0
CATEGORIES=		sysutils
MASTER_SITES=		http://www.ktools.org/dist/oak/

MAINTAINER=		jdwhite@jdwhite.org
HOMEPAGE=		http://www.ktools.org/dist/oak/
COMMENT=		System log reporting tool

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
BUILD_TARGET=

RCD_SCRIPTS=		oak
CONF_FILES=		${PREFIX}/share/examples/oak/oak.conf ${PKG_SYSCONFDIR}/oak.conf

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/oak
	${INSTALL_DATA}	${FILESDIR}/oak.conf* ${PREFIX}/share/examples/oak/
	${INSTALL_DATA} ${FILESDIR}/oak.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
