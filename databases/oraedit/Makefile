# $NetBSD: Makefile,v 1.8 2003/07/21 16:39:06 martti Exp $

DISTNAME=	oraedit-0.1.3
CATEGORIES=	databases
MASTER_SITES=	http://www.ics.muni.cz/~dolecek/projects/python/oraedit/

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	Editor of PL/SQL source stored in Oracle database

NO_CONFIGURE=	1
NO_BUILD=	1

PYTHON_PATCH_SCRIPTS=	oraedit

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oraedit ${LOCALBASE}/bin/oraedit

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
