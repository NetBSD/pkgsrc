# $NetBSD: Makefile,v 1.11 2004/08/30 12:39:19 schmonz Exp $
#

DISTNAME=		queue-repair-0.9.0
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		zuntum@NetBSD.org
HOMEPAGE=		http://www.qcc.sk.ca/~charlesc/software/queue_repair/
COMMENT=		Check or correct most corruptions of the queue in qmail

NO_BUILD=		YES

PYTHON_PATCH_SCRIPTS=	queue_repair.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/queue_repair.py ${PREFIX}/bin/queue_repair

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
