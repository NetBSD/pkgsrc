# $NetBSD: Makefile,v 1.12 2023/09/11 11:32:43 vins Exp $

DISTNAME=	toot-0.38.1
CATEGORIES=	chat net
MASTER_SITES=	${MASTER_SITE_PYPI:=t/toot/}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/ihabunek/toot
COMMENT=	Command line client for the Mastodon social network API
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-tomlkit-[0-9]*:../../textproc/py-tomlkit
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-urwid-[0-9]*:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-wcwidth-[0-9]*:../../devel/py-wcwidth

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
