# $NetBSD: Makefile,v 1.2 2026/09/08 23:04:50 agc Exp $

DISTNAME=		mldsa-${VERSION}
VERSION=		20260909
CATEGORIES=		security
MASTER_SITES=		-${MASTER_SITE_CODEBERG:=agc-codeberg/mldsa/archive/${VERSION}.tar.gz}

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		https://codeberg.org/agc-codeberg/mldsa/
COMMENT=		ML-DSA-65 post-quantum signing and verification
LICENSE=		mit

WRKSRC=			${WRKDIR}/mldsa

USE_LANGUAGES=		c

USE_BSD_MAKEFILE=	yes
AUTO_MKDIRS=		yes
TEST_TARGET=		t

BUILDLINK_API_DEPENDS.openssl+= openssl>=3.5	# needed for ML-DSA-65
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
