# $NetBSD: Makefile,v 1.4 2018/08/21 17:34:48 nia Exp $

DISTNAME=	tootstream-0.3.5
CATEGORIES=	chat www
MASTER_SITES=	${MASTER_SITE_GITHUB:=magicalraccoon/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/magicalraccoon/tootstream
COMMENT=	Command line interface for interacting with Mastodon instances
LICENSE=	mit

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE+=	27

DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-colored-[0-9]*:../../textproc/py-colored
DEPENDS+=	${PYPKGPREFIX}-emoji-[0-9]*:../../converters/py-emoji
DEPENDS+=	${PYPKGPREFIX}-humanize-[0-9]*:../../textproc/py-humanize
DEPENDS+=	${PYPKGPREFIX}-mastodon-[0-9]*:../../chat/py-mastodon
DEPENDS+=	${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
