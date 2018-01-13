# $NetBSD: Makefile,v 1.27 2018/01/13 18:22:42 adam Exp $

DISTNAME=	zeromq-4.2.3
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=zeromq/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zeromq.org/
COMMENT=	The ZeroMQ messaging library
LICENSE=	gnu-lgpl-v3

GITHUB_PROJECT=	libzmq
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

USE_LANGUAGES=		c gnu++11
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libsodium=${BUILDLINK_PREFIX.libsodium}

PKGCONFIG_OVERRIDE+=	src/libzmq.pc.in

TEST_TARGET=	check

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "SunOS"
.include "../../devel/libuuid/buildlink3.mk"
.endif
.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
