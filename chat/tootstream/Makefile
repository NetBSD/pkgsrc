# $NetBSD: Makefile,v 1.20 2023/10/23 06:37:35 wiz Exp $

DISTNAME=	tootstream-0.3.8.1
PKGREVISION=	6
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

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

# strange locale errors on earlier versions of python 3, related
# to py-click.
PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
