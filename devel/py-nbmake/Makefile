# $NetBSD: Makefile,v 1.2 2026/11/08 23:05:52 wiz Exp $

DISTNAME=	nbmake-1.5.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbmake/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/treebeardtech/nbmake
COMMENT=	Pytest plugin for testing notebooks
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-test>=6.1.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-nbclient>=0.6.6:../../www/py-nbclient
DEPENDS+=	${PYPKGPREFIX}-nbformat>=5.0.4:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-ipykernel>=5.4.0:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.7.3:../../textproc/py-pygments
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.12.2:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=3.6.1:../../devel/py-test-xdist

USE_LANGUAGES=	# none

# one test in tests/test_nb_run.py hangs? ctrl-c, then:
# 1 failed, 32 passed

.include "../../lang/python/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
