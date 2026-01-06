# $NetBSD: Makefile,v 1.9 2026/01/06 11:18:14 wiz Exp $

DISTNAME=	zulip-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=z/zulip/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zulip.com/
COMMENT=	Bindings for the Zulip message API
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-distro>=0:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-matrix-nio>=0:../../chat/py-matrix-nio
DEPENDS+=	${PYPKGPREFIX}-requests>=0.12.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.5.0:../../devel/py-typing-extensions

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-matrix-nio -> py-peewee -> py-sphinx

REPLACE_PYTHON+=	integrations/*.py
REPLACE_PYTHON+=	integrations/*/*
REPLACE_PYTHON+=	zulip/examples/*

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
