# $NetBSD: Makefile,v 1.9 2014/01/25 10:45:19 wiz Exp $
#

DISTNAME=		queue-repair-0.9.0
PKGREVISION=		5
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://pyropus.ca/software/queue-repair/
COMMENT=		Check or correct most corruptions of the queue in qmail

NO_BUILD=		YES

REPLACE_PYTHON=	queue_repair.py
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/queue_repair.py \
		${DESTDIR}${PREFIX}/bin/queue_repair

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
