# $NetBSD: Makefile,v 1.15 2024/03/17 11:47:57 vins Exp $

DISTNAME=	toot-0.42.0
CATEGORIES=	chat net
MASTER_SITES=	${MASTER_SITE_PYPI:=t/toot/}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/ihabunek/toot
COMMENT=	Command line client for the Mastodon social network API
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.5:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-click>=8.1:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-requests>=2.13:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.10.0:../../textproc/py-tomlkit
DEPENDS+=	${PYPKGPREFIX}-urwid>=2:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-urwidgets>=0:../../devel/py-urwidgets
DEPENDS+=	${PYPKGPREFIX}-wcwidth>=0.1.7:../../devel/py-wcwidth

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
