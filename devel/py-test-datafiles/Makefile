# $NetBSD: Makefile,v 1.1 2023/06/01 04:56:39 wiz Exp $

DISTNAME=	pytest-datafiles-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-datafiles/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/omarkohl/pytest-datafiles
COMMENT=	py.test plugin to create a 'tmp_path' containing predefined files/directories
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-test>=3.6:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
