# $NetBSD: Makefile,v 1.1 2000/01/31 14:03:00 jdolecek Exp $

DISTNAME=	oraedit-0.1.3
CATEGORIES=	databases
MASTER_SITES=	http://www.ics.muni.cz/~dolecek/projects/python/oraedit/

MAINTAINER=	jdolecek@netbsd.org

DEPENDS=	python:../../lang/python

NO_CONFIGURE=	1
NO_BUILD=	1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oraedit ${LOCALBASE}/bin/oraedit

.include "../../mk/bsd.pkg.mk"
