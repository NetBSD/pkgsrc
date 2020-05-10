# $NetBSD: Makefile,v 1.22 2020/05/10 17:27:27 rillig Exp $

DISTNAME=	libssh2-1.9.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://www.libssh2.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libssh2.org/
COMMENT=	SSH2 protocol library
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-libz=${BUILDLINK_PREFIX.zlib:Q}
CONFIGURE_ARGS+=	--disable-examples-build

PKGCONFIG_OVERRIDE+=	libssh2.pc.in
TEST_TARGET=		check

# patched in Makefile.in
CHECK_PORTABILITY_SKIP+=	Makefile.am

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
