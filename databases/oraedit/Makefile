# $NetBSD: Makefile,v 1.9 2004/10/02 08:30:02 jdolecek Exp $

DISTNAME=	oraedit-0.1.3
CATEGORIES=	databases
MASTER_SITES=	http://www.netbsd.cz/projects/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	Editor of PL/SQL source stored in Oracle database

NO_CONFIGURE=	1
NO_BUILD=	1

PYTHON_PATCH_SCRIPTS=	oraedit

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oraedit ${LOCALBASE}/bin/oraedit

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
