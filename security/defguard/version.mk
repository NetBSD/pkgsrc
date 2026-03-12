# $NetBSD: version.mk,v 1.3 2026/03/12 12:19:38 adam Exp $

DEFGUARD_VERSION=	1.6.4

CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_GITHUB:=defguard/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://defguard.net/
LICENSE=	gnu-agpl-v3 # AND defguard-enterprise-license

# All components need protos.
EXTRA_DIST+=	defguard-${DEFGUARD_VERSION}-proto${EXTRACT_SUFX}

DISTFILES=	${DEFAULT_DISTFILES} ${EXTRA_DIST}

TOOL_DEPENDS+=	protobuf>0:../../devel/protobuf
USE_TOOLS+=	pkg-config

MAKE_ENV+=	LIBGIT2_NO_VENDOR=1
MAKE_ENV+=	OPENSSL_DIR=${BUILDLINK_PREFIX.openssl}
MAKE_ENV+=	VERGEN_IDEMPOTENT=1
MAKE_ENV+=	VERGEN_GIT_SHA=pkgsrc
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.libgit2}/lib
RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.openssl}/lib

post-extract:
	${RMDIR} ${WRKSRC}/proto && ${LN} -f -s ${WRKDIR}/proto ${WRKSRC}/proto
