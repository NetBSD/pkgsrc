# $NetBSD: Makefile,v 1.2 2024/05/13 13:56:04 jperkin Exp $

DISTNAME=	zulip-0.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zulip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.zulip.org/
COMMENT=	Bindings for the Zulip message API
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-distro>=0:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-matrix-nio>=0:../../chat/py-matrix-nio
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.5.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-requests>=0.12.1:../../devel/py-requests

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

REPLACE_PYTHON+=	integrations/*.py
REPLACE_PYTHON+=	integrations/*/*
REPLACE_PYTHON+=	zulip/examples/*

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
