# $NetBSD: Makefile,v 1.4 2010/01/17 12:02:41 wiz Exp $
#

DISTNAME=	libssh2-1.2.2
PKGREVISION=	1
CATEGORIES=	security
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libssh2/}
MASTER_SITES=	http://www.libssh2.org/download/

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://libssh2.sourceforge.net/
COMMENT=	SSH2 protocol library

PKG_DESTDIR_SUPPORT=	user-destdir

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
