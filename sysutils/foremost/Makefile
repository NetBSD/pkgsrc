# $NetBSD: Makefile,v 1.6 2020/01/18 23:35:17 rillig Exp $

DISTNAME=	foremost-1.4
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://foremost.sourceforge.net/pkg/

MAINTAINER=	lkundrak@skosi.org
HOMEPAGE=	https://foremost.sourceforge.net/
COMMENT=	Recover various formats of files using typical data structures

EGDIR=		${PREFIX}/share/examples/foremost
CONF_FILES=	${EGDIR}/foremost.conf ${PKG_SYSCONFDIR}/foremost.conf

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1 ${EGDIR}
CPPFLAGS.SunOS+=	-Du_int64_t=uint64_t

.include "../../mk/bsd.pkg.mk"
