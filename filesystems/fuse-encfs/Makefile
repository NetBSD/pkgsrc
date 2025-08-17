# $NetBSD: Makefile,v 1.26 2025/08/17 19:59:03 wiz Exp $

DISTNAME=	encfs-1.9.5
PKGNAME=	fuse-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=vgough/}
GITHUB_PROJECT=	encfs
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vgough.github.io/encfs/
COMMENT=	FUSE Encrypted Filesystem
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	autoconf cmake pkg-config
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5
CMAKE_CONFIGURE_ARGS+=	-DUSE_INTERNAL_TINYXML=OFF

# Remediate open-coding in cmake that badly reimplements autoconf's
# --mandir=.
# \todo File a bug upstream.
SUBST_CLASSES+=		mandir
SUBST_STAGE.mandir=	pre-configure
SUBST_MESSAGE.mandir=	Remediating cmake PKGMANDIR
SUBST_FILES.mandir=	CMakeLists.txt
SUBST_SED.mandir=	-E -e "/MAN_DESTINATION/s,share/man,${PKGMANDIR},"

# \todo Add TEST_DEPENDS for unittest, after finding it or packaging
# it.
TEST_TARGET=	test

.include "../../devel/cmake/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/tinyxml2/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
