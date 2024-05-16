# $NetBSD: Makefile,v 1.5 2024/05/16 06:15:16 wiz Exp $

DISTNAME=	czmq-4.2.1
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=zeromq/}
GITHUB_PROJECT=	czmq
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://czmq.zeromq.org/
COMMENT=	High-level C binding for ZeroMQ
LICENSE=	mpl-2.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	src/libczmq.pc.in

CONFIGURE_ARGS+=	--with-libsystemd=no
CONFIGURE_ARGS+=	--with-docs=no
CONFIGURE_ARGS+=	--enable-drafts=yes

TEST_TARGET=	check

.include "../../archivers/lz4/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../net/zeromq/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
