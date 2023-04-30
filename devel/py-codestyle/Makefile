# $NetBSD: Makefile,v 1.12 2023/04/30 14:36:13 wiz Exp $

DISTNAME=	pycodestyle-2.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycodestyle/}

MAINTAINER=	wenheping@gmail.com
HOMEPAGE=	https://github.com/PyCQA/pycodestyle
COMMENT=	Python style guide checker
LICENSE=	mit

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pycodestyle pycodestyle-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m unittest -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
