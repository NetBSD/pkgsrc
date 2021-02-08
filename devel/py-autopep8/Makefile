# $NetBSD: Makefile,v 1.16 2021/02/08 14:36:24 adam Exp $

DISTNAME=	autopep8-1.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/autopep8/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/hhatto/autopep8
COMMENT=	Automatic formatter of Python code to conform to PEP 8
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-codestyle>=2.6.0:../../devel/py-codestyle
DEPENDS+=	${PYPKGPREFIX}-toml-[0-9]*:../../textproc/py-toml

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} autopep8 autopep8-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
