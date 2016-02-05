# $NetBSD: Makefile,v 1.1 2016/02/05 21:01:46 jmmv Exp $
#

DISTNAME=	fuse-pcachefs-0.0.20160203
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=ibizaman/}
GITHUB_PROJECT=	pcachefs
GITHUB_TAG=	0712601d2b3fc2667112be106133ae162e98d7a5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibizaman/pcachefs
COMMENT=	FUSE-based persistent caching filesystem
LICENSE=	apache-2.0

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

EGG_NAME=	pCacheFS-0.2
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-fuse-bindings

.include "../../filesystems/py-fuse-bindings/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
