# $NetBSD: Makefile,v 1.9 2003/07/21 16:56:55 martti Exp $
#

DISTNAME=	queue-repair-0.8.4
CATEGORIES=	mail
MASTER_SITES=	http://www.qcc.sk.ca/~charlesc/software/queue_repair/

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	Check or correct most corruptions of the queue in qmail

NO_BUILD=	YES

PYTHON_PATCH_SCRIPTS=	queue_repair.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/queue_repair.py ${PREFIX}/bin/queue_repair

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
