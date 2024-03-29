# $NetBSD: Makefile,v 1.82 2024/02/08 06:18:00 adam Exp $

DISTNAME=	libuv-1.48.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libuv/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	agc@pkgsrc.org
HOMEPAGE=	https://github.com/libuv/libuv
COMMENT=	Cross-platform asychronous I/O
LICENSE=	mit AND 2-clause-bsd AND isc AND modified-bsd

USE_CC_FEATURES=	c11
FORCE_CC_STD=		c11 # stdatomic.h

USE_LANGUAGES=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake pkg-config
USE_FEATURES+=	strnlen
GNU_CONFIGURE=	yes
# 3 test failures as of 1.31.0
# https://github.com/libuv/libuv/issues/2437
# connect_unspecified, tcp_open, udp_open
TEST_ENV=	UV_RUN_AS_ROOT=yes
TEST_TARGET=	check

INSTALLATION_DIRS+=	include/uv

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_PLATFORM:MSunOS-5.[0-9]-*} || \
    ${MACHINE_PLATFORM:MSunOS-5.10-*}
CFLAGS+=	-DSUNOS_NO_IFADDRS
.endif

pre-configure:
	${RUN} cd ${WRKSRC} && ${SH} ./autogen.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/uv/* ${DESTDIR}${PREFIX}/include/uv/

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
