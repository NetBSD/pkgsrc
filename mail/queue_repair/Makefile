# $NetBSD: Makefile,v 1.12 2005/02/16 18:44:36 schmonz Exp $
#

DISTNAME=		queue-repair-0.9.0
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/queue_repair/
COMMENT=		Check or correct most corruptions of the queue in qmail

NO_BUILD=		YES

PYTHON_PATCH_SCRIPTS=	queue_repair.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/queue_repair.py ${PREFIX}/bin/queue_repair

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
