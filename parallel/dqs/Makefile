# $NetBSD: Makefile,v 1.3 2003/07/21 17:12:23 martti Exp $
#

DISTNAME=	DQS-3.3.2
PKGNAME=	dqs-3.3.2
CATEGORIES=	parallel
MASTER_SITES=	http://www.go.dlr.de/fresh/unix/src/misc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.scri.fsu.edu/~pasko/dqs.html
COMMENT=	Distributed queueing system

WRKSRC=		${WRKDIR}/DQS3
USE_PKGINSTALL=	yes

EGDIR=		${PREFIX}/share/examples/dqs
CONF_FILES+=	${EGDIR}/conf_file ${PKG_SYSCONFDIR}/conf_file
CONF_FILES+=	${EGDIR}/key_file ${PKG_SYSCONFDIR}/key_file
CONF_FILES+=	${EGDIR}/resolve_file ${PKG_SYSCONFDIR}/resolve_file

.include "../../mk/bsd.pkg.mk"
