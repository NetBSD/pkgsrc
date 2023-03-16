# $NetBSD: Makefile,v 1.2 2023/03/16 17:40:32 adam Exp $

DISTNAME=	pyleri-1.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyleri/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cesbit/pyleri
COMMENT=	Python Left-Right Parser
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m unittest test/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
