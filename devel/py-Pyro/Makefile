# $NetBSD: Makefile,v 1.30 2022/02/09 21:25:58 adam Exp $

DISTNAME=	Pyro4-4.82
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pyro4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/irmen/Pyro4
COMMENT=	Distributed Object Technology system in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-serpent>=1.27:../../devel/py-serpent
TEST_DEPENDS+=	${PYPKGPREFIX}-msgpack>=0.5.2:../../devel/py-msgpack

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-serpent

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pyro4-check-config pyro4-check-config-${PYVERSSUFFIX} && \
	${MV} pyro4-flameserver pyro4-flameserver-${PYVERSSUFFIX} && \
	${MV} pyro4-httpgateway pyro4-httpgateway-${PYVERSSUFFIX} && \
	${MV} pyro4-ns pyro4-ns-${PYVERSSUFFIX} && \
	${MV} pyro4-nsc pyro4-nsc-${PYVERSSUFFIX} && \
	${MV} pyro4-test-echoserver pyro4-test-echoserver-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}/tests && ${PYTHONBIN} run_testsuite.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
