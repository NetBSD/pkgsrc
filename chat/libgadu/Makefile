# $NetBSD: Makefile,v 1.8 2020/06/02 08:23:19 adam Exp $

DISTNAME=	libgadu-1.12.2
PKGREVISION=	5
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=wojtekka/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://libgadu.net/
COMMENT=	Library for handling the protocol of Gadu-Gadu
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake gmake perl:test pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-bind
# XXX: https://github.com/wojtekka/libgadu/issues/25
CONFIGURE_ARGS+=	--without-pthread
PKGCONFIG_OVERRIDE+=	pkgconfig/libgadu.pc.in
TEST_TARGET=		check

REPLACE_PERL=	test/protocol/compile

pre-configure:
	cd ${WRKSRC} && \
	${SETENV} NOCONFIGURE=no ${SH} ./autogen.sh

.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
