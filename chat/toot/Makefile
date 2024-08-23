# $NetBSD: Makefile,v 1.16 2024/08/23 13:15:15 vins Exp $

DISTNAME=		toot-0.44.1
CATEGORIES=		chat net
MASTER_SITES=		${MASTER_SITE_PYPI:=t/toot/}
#MASTER_SITES=		${MASTER_SITE_GITHUB:=ihabunek/}
#GITHUB_PROJECT=	toot
#GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://toot.bezdomni.net/
COMMENT=	Command line client for the Mastodon social network API
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.5:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-click>=8.1:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-requests>=2.13:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.10.0:../../textproc/py-tomlkit
DEPENDS+=	${PYPKGPREFIX}-urwid>=2:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-urwidgets>=0.2:../../devel/py-urwidgets
DEPENDS+=	${PYPKGPREFIX}-wcwidth>=0.1.7:../../devel/py-wcwidth

TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
