# $NetBSD: Makefile,v 1.3 2000/12/28 14:53:52 wiz Exp $

DISTNAME=	oraedit-0.1.3
CATEGORIES=	databases
MASTER_SITES=	http://www.ics.muni.cz/~dolecek/projects/python/oraedit/

MAINTAINER=	jdolecek@netbsd.org

DEPENDS=	python>=1.5:../../lang/python

NO_CONFIGURE=	1
NO_BUILD=	1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oraedit ${LOCALBASE}/bin/oraedit

.include "../../mk/bsd.pkg.mk"
