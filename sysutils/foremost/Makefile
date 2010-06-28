# $NetBSD: Makefile,v 1.3 2010/06/28 10:18:58 joerg Exp $

DISTNAME=	foremost-1.4
CATEGORIES=	sysutils
MASTER_SITES=	http://foremost.sourceforge.net/pkg/

MAINTAINER=	lkundrak@skosi.org
HOMEPAGE=	http://foremost.sourceforge.net/
COMMENT=	Recover various formats of files using typical data structures

PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=		${PREFIX}/share/examples/foremost
CONF_FILES=	${EGDIR}/foremost.conf ${PKG_SYSCONFDIR}/foremost.conf

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${EGDIR}

.include "../../mk/bsd.pkg.mk"
