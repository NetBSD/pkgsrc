# $NetBSD: Makefile,v 1.9 2015/03/28 19:00:28 rodent Exp $
#

DISTNAME=		polarssl-1.3.9-gpl
PKGNAME=		${DISTNAME:-gpl=}
PKGREVISION=		1
CATEGORIES=		security devel
MASTER_SITES=		https://tls.mbed.org/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://tls.mbed.org/
COMMENT=		Lightweight, modular cryptographic and SSL/TLS library
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		gmake perl pkg-config
USE_CMAKE=		yes
REPLACE_PERL=		tests/scripts/*.pl
USE_LANGUAGES=		c
TEST_TARGET=		check

.include "options.mk"

CMAKE_ARGS+=		-DUSE_SHARED_POLARSSL_LIBRARY=ON
MAKE_ENV+=		RANLIB=${RANLIB:Q}

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/libpolarssl.a

.include "../../mk/pthread.buildlink3.mk"
#.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
