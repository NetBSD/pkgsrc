# $NetBSD: Makefile,v 1.14 2006/02/05 23:08:32 joerg Exp $

DISTNAME=	oraedit-0.1.4
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.netbsd.cz/projects/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	Editor of PL/SQL source stored in Oracle database

NO_CONFIGURE=	yes
NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	oraedit
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oraedit ${PREFIX}/bin/oraedit

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
