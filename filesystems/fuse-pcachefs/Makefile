# $NetBSD: Makefile,v 1.10 2020/12/04 20:45:17 nia Exp $

DISTNAME=	fuse-pcachefs-0.0.20160203
PKGREVISION=	2
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=ibizaman/}
GITHUB_PROJECT=	pcachefs
GITHUB_TAG=	0712601d2b3fc2667112be106133ae162e98d7a5

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ibizaman/pcachefs
COMMENT=	FUSE-based persistent caching filesystem
LICENSE=	apache-2.0

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools:build

EGG_NAME=	pCacheFS-0.2
PYTHON_VERSIONS_ACCEPTED= 27 # py-fuse-bindings

.include "../../filesystems/py-fuse-bindings/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
