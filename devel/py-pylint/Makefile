# $NetBSD: Makefile,v 1.55 2021/09/13 06:52:31 adam Exp $

DISTNAME=	pylint-2.10.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pylint.org/
COMMENT=	Python source code analyzer
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-astroid>=2.7.2:../../devel/py-astroid
DEPENDS+=	${PYPKGPREFIX}-isort>=4.2.5:../../devel/py-isort
DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.6:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2.2.0:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-toml>=0.7.1:../../textproc/py-toml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for file in epylint pylint pyreverse symilar
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${file} ${file}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
