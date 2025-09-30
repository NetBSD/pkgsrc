# $NetBSD: Makefile,v 1.5 2025/09/30 14:24:38 wiz Exp $

DISTNAME=	pytest_textual_snapshot-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest_textual_snapshot/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Textualize/pytest-textual-snapshot
COMMENT=	Snapshot testing for Textual apps
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-rich>=12.0.0:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-syrupy>=4.8.0:../../devel/py-syrupy
DEPENDS+=	${PYPKGPREFIX}-test>=8.0.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-textual>=0.28.0:../../comms/py-textual

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
