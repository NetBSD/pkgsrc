# $NetBSD: Makefile,v 1.4 2012/10/23 19:51:02 asau Exp $

DISTNAME=	foremost-1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://foremost.sourceforge.net/pkg/

MAINTAINER=	lkundrak@skosi.org
HOMEPAGE=	http://foremost.sourceforge.net/
COMMENT=	Recover various formats of files using typical data structures

EGDIR=		${PREFIX}/share/examples/foremost
CONF_FILES=	${EGDIR}/foremost.conf ${PKG_SYSCONFDIR}/foremost.conf

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${EGDIR}

.include "../../mk/bsd.pkg.mk"
