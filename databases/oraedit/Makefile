# $NetBSD: Makefile,v 1.6 2002/09/21 23:46:46 jlam Exp $

DISTNAME=	oraedit-0.1.3
CATEGORIES=	databases
MASTER_SITES=	http://www.ics.muni.cz/~dolecek/projects/python/oraedit/

MAINTAINER=	jdolecek@netbsd.org
COMMENT=	editor of PL/SQL source stored in Oracle database

NO_CONFIGURE=	1
NO_BUILD=	1

PYTHON_PATCH_SCRIPTS=	oraedit

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oraedit ${LOCALBASE}/bin/oraedit

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
