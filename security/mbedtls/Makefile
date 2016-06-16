# $NetBSD: Makefile,v 1.3 2016/06/16 14:17:03 fhajny Exp $
#

DISTNAME=		mbedtls-2.2.1-apache
PKGNAME=		${DISTNAME:-apache=}
CATEGORIES=		security devel
MASTER_SITES=		https://tls.mbed.org/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://tls.mbed.org/
COMMENT=		Lightweight, modular cryptographic and SSL/TLS library
LICENSE=		apache-2.0

CONFLICTS+=		polarssl-[0-9]*
SUPERSEDES+=		polarssl-[0-9]*

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_CMAKE=		yes
USE_LANGUAGES=		c
USE_TOOLS+=		gmake perl pkg-config

GCC_REQD+=		4.4
REPLACE_PERL=		tests/scripts/*.pl

.include "options.mk"

CMAKE_ARGS+=		-DUSE_SHARED_MBEDTLS_LIBRARY=ON
MAKE_ENV+=		RANLIB=${RANLIB:Q}

LDFLAGS.SunOS+=		-lsocket

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
