# $NetBSD: Makefile,v 1.58 2022/01/04 20:53:23 wiz Exp $

DISTNAME=	pylint-2.12.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pylint.org/
COMMENT=	Python source code analyzer
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-astroid>=2.9.0:../../devel/py-astroid
DEPENDS+=	${PYPKGPREFIX}-isort>=4.2.5:../../devel/py-isort
DEPENDS+=	${PYPKGPREFIX}-mccabe>=0.6:../../devel/py-mccabe
DEPENDS+=	${PYPKGPREFIX}-platformdirs>=2.2.0:../../misc/py-platformdirs
DEPENDS+=	${PYPKGPREFIX}-toml>=0.9.2:../../textproc/py-toml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=3.10.0:../../devel/py-typing-extensions
.endif

post-install:
.for file in epylint pylint pyreverse symilar
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${file} ${file}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
