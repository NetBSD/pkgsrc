# $NetBSD: Makefile,v 1.35 2023/10/11 05:43:08 adam Exp $

DISTNAME=	zeromq-4.3.5
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=zeromq/}
GITHUB_PROJECT=	libzmq
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zeromq.org/
COMMENT=	The ZeroMQ messaging library
LICENSE=	mpl-2.0

USE_LANGUAGES=		c99 gnu++11
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libsodium=${BUILDLINK_PREFIX.libsodium}
PKGCONFIG_OVERRIDE+=	src/libzmq.pc.in
TEST_TARGET=		check

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.include "../../devel/libuuid/buildlink3.mk"
.endif
.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
