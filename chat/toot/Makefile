# $NetBSD: Makefile,v 1.24 2026/04/19 18:45:09 vins Exp $

DISTNAME=	toot-0.52.1
CATEGORIES=	chat net
MASTER_SITES=	${MASTER_SITE_PYPI:=t/toot/}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://toot.bezdomni.net/
COMMENT=	Command line client for the Mastodon social network API
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=8:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.5.0:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-click>=8.1:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-dateutil>=2.8.1:../../time/py-dateutil
DEPENDS+=	${PYPKGPREFIX}-requests>=2.13:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.10.0:../../textproc/py-tomlkit
DEPENDS+=	${PYPKGPREFIX}-urwid>=3.0.0:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-wcwidth>=0.1.7:../../devel/py-wcwidth
# richtext
DEPENDS+=	${PYPKGPREFIX}-urwidgets>=0.2:../../devel/py-urwidgets
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
