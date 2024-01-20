# $NetBSD: Makefile,v 1.2 2024/01/20 09:57:58 adam Exp $

DISTNAME=	ghp-import-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/ghp-import/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/c-w/ghp-import
COMMENT=	Copy your docs directly to the gh-pages branch
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.1:../../time/py-dateutil

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ghp-import ghp-import-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
