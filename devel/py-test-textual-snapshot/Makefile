# $NetBSD: Makefile,v 1.1 2024/07/14 12:31:18 wiz Exp $

DISTNAME=	pytest_textual_snapshot-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/g}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest_textual_snapshot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/darrenburns/pytest-textual-snapshot
COMMENT=	Snapshot testing for Textual apps
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core-[0-9]*:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-test>=7.0.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-rich>=12.0.0:../../comms/py-rich
# py-textual uses this for testing
DEPENDS+=	${PYPKGPREFIX}-textual>=0.28.0:../../comms/py-textual
DEPENDS+=	${PYPKGPREFIX}-syrupy>=3.0.0:../../devel/py-syrupy

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
