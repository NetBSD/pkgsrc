# $NetBSD: Makefile,v 1.5 2011/02/28 14:53:01 wiz Exp $
#

DISTNAME=	libssh2-1.2.2
PKGREVISION=	1
CATEGORIES=	security
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libssh2/}
MASTER_SITES=	http://www.libssh2.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
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
