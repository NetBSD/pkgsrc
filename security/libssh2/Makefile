# $NetBSD: Makefile,v 1.17 2019/04/01 14:21:14 wiz Exp $

DISTNAME=	libssh2-1.8.2
CATEGORIES=	security
MASTER_SITES=	https://www.libssh2.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libssh2.org/
COMMENT=	SSH2 protocol library
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-libgcrypt=no
CONFIGURE_ARGS+=	--with-libz=${BUILDLINK_PREFIX.zlib:Q}
CONFIGURE_ARGS+=	--with-openssl=${SSLBASE:Q}

PKGCONFIG_OVERRIDE+=	libssh2.pc.in
TEST_TARGET=		check

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
