# $NetBSD: Makefile,v 1.13 2017/06/19 18:41:39 maya Exp $
#

DISTNAME=	encfs-1.9.1
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=vgough/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.arg0.net/encfs
COMMENT=	FUSE Encrypted Filesystem
LICENSE=	gnu-gpl-v3

GITHUB_PROJECT=	encfs
GITHUB_TAG=	v${PKGVERSION_NOREV}


USE_TOOLS+=	autoconf cmake pkg-config
USE_CMAKE=	yes
USE_LANGUAGES=	c c++

CONFIGURE_DIRS=	${WRKDIR}/build
CMAKE_ARG_PATH=	${WRKSRC}

TEST_TARGET=	test

post-extract:
	${RUN} mkdir -p ${WRKDIR}/build

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
