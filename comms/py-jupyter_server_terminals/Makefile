# $NetBSD: Makefile,v 1.8 2026/01/14 18:55:43 adam Exp $

DISTNAME=	jupyter_server_terminals-0.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter-server-terminals/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jupyter.org/
COMMENT=	Jupyter Server Extension Providing Terminals
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.5:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-terminado>=0.8.3:../../www/py-terminado
TEST_DEPENDS+=	${PYPKGPREFIX}-jupyter_server>=2.0.0:../../www/py-jupyter_server
TEST_DEPENDS+=	${PYPKGPREFIX}-test-jupyter>=0.5.3:../../www/py-test-jupyter
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
