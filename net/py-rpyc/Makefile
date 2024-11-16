# $NetBSD: Makefile,v 1.10 2024/11/16 10:21:32 adam Exp $

DISTNAME=	rpyc-6.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rpyc/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://rpyc.readthedocs.io/
COMMENT=	Remote Python Call (RPyC), a transparent and symmetric RPC library
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.6.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-plumbum>=1.6.1:../../devel/py-plumbum

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	rpyc/cli/rpyc_classic.py
REPLACE_PYTHON+=	rpyc/cli/rpyc_registry.py

post-install:
.for bin in rpyc_classic rpyc_registry
	cd ${DESTDIR}${PREFIX}/bin && \
	${RM} ${bin}.py && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
