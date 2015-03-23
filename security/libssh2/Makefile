# $NetBSD: Makefile,v 1.11 2015/03/23 09:14:53 nros Exp $
#

DISTNAME=	libssh2-1.5.0
CATEGORIES=	security
MASTER_SITES=	http://www.libssh2.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libssh2.org/
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
