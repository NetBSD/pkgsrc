# $NetBSD: Makefile,v 1.5 2019/08/11 13:22:47 wiz Exp $
#

DISTNAME=		mbedtls-1.3.17-gpl
PKGNAME=		${DISTNAME:-gpl=}
PKGREVISION=		2
CATEGORIES=		security devel
MASTER_SITES=		https://tls.mbed.org/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://tls.mbed.org/
COMMENT=		Lightweight, modular cryptographic and SSL/TLS library
LICENSE=		gnu-gpl-v2

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

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/libmbedtls.a
	${SETENV} ${SH} ${WRKSRC}/scripts/polarssl_symlinks.sh ${DESTDIR}${PREFIX}/lib

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
