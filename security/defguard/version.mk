# $NetBSD: version.mk,v 1.2 2025/10/21 18:31:28 adam Exp $
DEFGUARD_VERSION=	1.5.1

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

MAKE_ENV+=	VERGEN_IDEMPOTENT=1
MAKE_ENV+=	VERGEN_GIT_SHA=pkgsrc

post-extract:
	${RMDIR} ${WRKSRC}/proto && ${LN} -f -s ${WRKDIR}/proto ${WRKSRC}/proto
