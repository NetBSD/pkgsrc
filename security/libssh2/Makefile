# $NetBSD: Makefile,v 1.25 2023/10/24 22:10:51 wiz Exp $

DISTNAME=	libssh2-1.11.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://www.libssh2.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libssh2.org/
COMMENT=	SSH2 protocol library
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libz=${BUILDLINK_PREFIX.zlib:Q}
CONFIGURE_ARGS+=	--disable-examples-build
PKGCONFIG_OVERRIDE+=	libssh2.pc.in
TEST_TARGET=		check

# patched in Makefile.in
CHECK_PORTABILITY_SKIP+=	Makefile.am

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
