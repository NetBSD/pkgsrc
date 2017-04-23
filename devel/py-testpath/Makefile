# $NetBSD: Makefile,v 1.1 2017/04/23 05:04:02 markd Exp $

DISTNAME=	testpath-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=jupyter/}
GITHUB_PROJECT=	testpath

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyter/testpath
COMMENT=	Test utilities for code working with files and commands
LICENSE=	mit

USE_LANGUAGES=	# none

NO_BUILD=	yes
PY_PATCHPLIST=	yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${PYSITELIB}/testpath
	${INSTALL_DATA} ${WRKSRC}/testpath/*.py ${DESTDIR}${PREFIX}/${PYSITELIB}/testpath/

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
