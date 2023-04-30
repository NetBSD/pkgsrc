# $NetBSD: Makefile,v 1.22 2023/04/30 14:41:14 wiz Exp $

DISTNAME=	autopep8-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/autopep8/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/hhatto/autopep8
COMMENT=	Automatic formatter of Python code to conform to PEP 8
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.10.0:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} autopep8 autopep8-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
