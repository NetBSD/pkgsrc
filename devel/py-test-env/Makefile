# $NetBSD: Makefile,v 1.1 2021/09/03 12:05:17 gdt Exp $

DISTNAME=	pytest-env-0.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-env/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MobileDynasty/pytest-env
COMMENT=	Plugin for py.test that allows you to add environment variables

LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-test>=2.6.0:../../devel/py-test

# This likely works with 27, but for now omit versioned deps.
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

USE_LANGUAGES=	# none
USE_TOOLS+=	bash:build

do-test:
	cd ${WRKSRC}/testing && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
