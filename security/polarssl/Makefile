# $NetBSD: Makefile,v 1.14 2015/06/12 10:51:10 wiz Exp $
#

DISTNAME=		polarssl-1.3.9-gpl
PKGNAME=		${DISTNAME:-gpl=}
PKGREVISION=		2
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
GCC_REQD+=		4.4

.include "options.mk"

CMAKE_ARGS+=		-DUSE_SHARED_POLARSSL_LIBRARY=ON
MAKE_ENV+=		RANLIB=${RANLIB:Q}

LDFLAGS.SunOS+=		-lsocket

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/libpolarssl.a

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
