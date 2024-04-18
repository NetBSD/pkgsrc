# $NetBSD: Makefile,v 1.1 2024/04/18 04:02:26 pho Exp $

DISTNAME=	fuse-s3fs-${PKGVERSION}
PKGVERSION=	1.94
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_GITHUB:=s3fs-fuse/}
GITHUB_PROJECT=	s3fs-fuse
GITHUB_TAG=	v${PKGVERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/s3fs-fuse/s3fs-fuse
COMMENT=	FUSE file-system and utilities for S3-compatible APIs
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++11
USE_TOOLS+=		autoheader automake autoreconf gmake pkg-config

# configure.ac uses a non-standard option "-r" for date(1). "stat -f" is
# GNU-ism and "stat -t" is BSD-ism. There seems to be no portable way to do
# this! So always use gdate from coreutils.
USE_TOOLS+=		date
TOOLS_PATH.date=	${TOOLBASE}/bin/gdate
TOOL_DEPENDS+=		coreutils-[0-9]*:../../sysutils/coreutils

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=   opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
