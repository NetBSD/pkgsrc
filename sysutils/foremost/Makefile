# $NetBSD: Makefile,v 1.1.1.1 2007/01/26 16:36:29 minskim Exp $

DISTNAME=	foremost-1.3
CATEGORIES=	sysutils
MASTER_SITES=	http://foremost.sourceforge.net/pkg/

MAINTAINER=	lkundrak@skosi.org
HOMEPAGE=	http://foremost.sourceforge.net/
COMMENT=	Recover various formats of files using typical data structures

EGDIR=		${PREFIX}/share/examples/foremost
CONF_FILES=	${EGDIR}/foremost.conf ${PKG_SYSCONFDIR}/foremost.conf

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}

.include "../../mk/bsd.pkg.mk"
