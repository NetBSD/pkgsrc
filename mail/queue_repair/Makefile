# $NetBSD: Makefile,v 1.5 2001/09/27 23:18:23 jlam Exp $
#

DISTNAME=	queue-repair-0.8.4
CATEGORIES=	mail
MASTER_SITES=	http://www.qcc.sk.ca/~charlesc/software/queue_repair/

MAINTAINER=	zuntum@netbsd.org
COMMENT=	check or correct most corruptions of the queue in qmail

DEPENDS+=	python-[0-9]*:../../lang/python

NO_BUILD=	YES

post-patch:
	${SED} "s,/usr/bin/python,${LOCALBASE}/bin/python,"		\
		${WRKSRC}/queue_repair.py > ${WRKSRC}/queue_repair.py.done
	${MV} ${WRKSRC}/queue_repair.py.done ${WRKSRC}/queue_repair.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/queue_repair.py ${PREFIX}/bin/queue_repair

.include "../../mk/bsd.pkg.mk"
