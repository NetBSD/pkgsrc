# $NetBSD: Makefile,v 1.14 2026/10/16 17:44:06 adam Exp $

DISTNAME=	pydocstyle-6.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydocstyle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyCQA/pydocstyle
COMMENT=	Python docstring style checker
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-snowballstemmer>=0:../../textproc/py-snowballstemmer

PY_RENAME_BINARIES=	pydocstyle

post-extract:
	${CHMOD} go-w ${WRKSRC}/src/pydocstyle/data/*.txt

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
