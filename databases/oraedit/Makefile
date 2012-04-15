# $NetBSD: Makefile,v 1.21 2012/04/15 22:00:59 wiz Exp $

DISTNAME=	oraedit-0.1.4
PKGREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_BACKUP}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Editor of PL/SQL source stored in Oracle database

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=	oraedit
INSTALLATION_DIRS=	bin

do-configure:;

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/oraedit ${DESTDIR}${PREFIX}/bin/oraedit

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
