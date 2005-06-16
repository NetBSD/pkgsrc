# $NetBSD: Makefile,v 1.11 2005/06/16 06:57:44 jlam Exp $

DISTNAME=	oraedit-0.1.4
CATEGORIES=	databases
MASTER_SITES=	http://www.netbsd.cz/projects/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	Editor of PL/SQL source stored in Oracle database

NO_CONFIGURE=	1
NO_BUILD=	1

PYTHON_PATCH_SCRIPTS=	oraedit
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oraedit ${LOCALBASE}/bin/oraedit

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
