# $NetBSD: Makefile,v 1.10 2023/04/30 15:23:08 wiz Exp $

DISTNAME=	pydocstyle-6.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydocstyle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/PyCQA/pydocstyle
COMMENT=	Python docstring style checker
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-snowballstemmer-[0-9]*:../../textproc/py-snowballstemmer

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

.include "../../lang/python/pyversion.mk"

.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli-[0-9]*:../../textproc/py-tomli
.endif

.if ${PYTHON_VERSION} < 308
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
.endif

post-extract:
	${CHMOD} go-w ${WRKSRC}/src/pydocstyle/data/*.txt

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} pydocstyle pydocstyle-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
