# $NetBSD: Makefile,v 1.4 2001/02/16 14:17:30 wiz Exp $

DISTNAME=	oraedit-0.1.3
CATEGORIES=	databases
MASTER_SITES=	http://www.ics.muni.cz/~dolecek/projects/python/oraedit/

MAINTAINER=	jdolecek@netbsd.org
COMMENT=	editor of PL/SQL source stored in Oracle database

DEPENDS=	python>=1.5:../../lang/python

NO_CONFIGURE=	1
NO_BUILD=	1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oraedit ${LOCALBASE}/bin/oraedit

.include "../../mk/bsd.pkg.mk"
