# $NetBSD: Makefile,v 1.9 2026/05/15 16:00:55 vins Exp $

DISTNAME=	unionfs-fuse-3.7
PKGNAME=	${DISTNAME:S/unionfs-fuse/fuse-unionfs/}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=rpodgorny/}
GITHUB_PROJECT=	unionfs-fuse
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rpodgorny/unionfs-fuse
COMMENT=	FUSE-based union filesystem
LICENSE=	modified-bsd

BUILD_TARGET=	build
TEST_TARGET=	test

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_TOOLS+=	gmake pkg-config bash:run
USE_FUSE3=	yes

PYTHON_FOR_BUILD_ONLY=		test
PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_BASH+=	mount.unionfs
REPLACE_PYTHON=	test_all.py

MAKE_ENV+=	PREFIX=${PREFIX} \
		MANDIR=${PKGMANDIR} \
		PYTHON=${PYTHONBIN:Q}

.include "../../lang/python/pyversion.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
