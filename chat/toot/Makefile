# $NetBSD: Makefile,v 1.5 2023/01/18 06:32:09 vins Exp $

DISTNAME=	toot-0.33.1
CATEGORIES=	chat net
MASTER_SITES=	${MASTER_SITE_PYPI:=t/toot/}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/ihabunek/toot
COMMENT=	Command line client for the Mastodon social network API
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-urwid-[0-9]*:../../devel/py-urwid
DEPENDS+=	${PYPKGPREFIX}-wcwidth-[0-9]*:../../devel/py-wcwidth

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
