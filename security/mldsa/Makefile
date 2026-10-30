# $NetBSD: Makefile,v 1.4 2026/10/30 21:34:16 agc Exp $

DISTNAME=		mldsa-${VERSION}
PKGNAME=		libmldsa-${VERSION}
VERSION=		20261029
CATEGORIES=		security
MASTER_SITES=		-${MASTER_SITE_CODEBERG:=agc-codeberg/mldsa/archive/${VERSION}.tar.gz}

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		https://codeberg.org/agc-codeberg/mldsa/
COMMENT=		ML-DSA-65 post-quantum signing and verification
LICENSE=		mit

WRKSRC=			${WRKDIR}/mldsa/dist

USE_LANGUAGES=		c

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
MAKE_FILE=		Makefile.libtool
AUTO_MKDIRS=		yes
TEST_TARGET=		t

_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}

.include "../../security/liboqs/buildlink3.mk"

BUILDLINK_API_DEPENDS.openssl+= openssl>=3.5	# needed for ML-DSA-65
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
