# $NetBSD: Makefile,v 1.6 2002/01/18 16:23:27 drochner Exp $
#

DISTNAME=	queue-repair-0.8.4
CATEGORIES=	mail
MASTER_SITES=	http://www.qcc.sk.ca/~charlesc/software/queue_repair/

MAINTAINER=	zuntum@netbsd.org
COMMENT=	check or correct most corruptions of the queue in qmail

NO_BUILD=	YES

PYTHON_PATCH_SCRIPTS=	queue_repair.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/queue_repair.py ${PREFIX}/bin/queue_repair

.include "../../lang/python/application.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
