# $NetBSD: Makefile,v 1.22 2024/10/14 08:11:12 nia Exp $

DISTNAME=	tootstream-0.4.0
CATEGORIES=	chat www
MASTER_SITES=	${MASTER_SITE_GITHUB:=magicalraccoon/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/magicalraccoon/tootstream
COMMENT=	Command line interface for interacting with Mastodon instances
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-click>=6.7:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-colored>=1.3.93:../../textproc/py-colored
DEPENDS+=	${PYPKGPREFIX}-emoji>=0.4.5:../../converters/py-emoji
DEPENDS+=	${PYPKGPREFIX}-humanize>=0.5.1:../../textproc/py-humanize
DEPENDS+=	${PYPKGPREFIX}-mastodon>=1.5.0:../../chat/py-mastodon
DEPENDS+=	${PYPKGPREFIX}-pytimeparse>=0:../../time/py-pytimeparse

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
