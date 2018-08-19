# $NetBSD: Makefile,v 1.38 2018/08/19 18:12:22 wiz Exp $

DISTNAME=	libuv-1.23.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libuv/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	agc@pkgsrc.org
HOMEPAGE=	https://github.com/libuv/libuv
COMMENT=	Cross-platform asychronous I/O
LICENSE=	mit AND 2-clause-bsd AND isc AND modified-bsd

USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake pkg-config
GNU_CONFIGURE=	yes
TEST_TARGET=	check

INSTALLATION_DIRS+=	include/uv

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MSunOS-5.[0-9]-*) || \
    !empty(MACHINE_PLATFORM:MSunOS-5.10-*)
CFLAGS+=	-DSUNOS_NO_IFADDRS
.endif

pre-configure:
	${RUN} cd ${WRKSRC} && ${SH} ./autogen.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/uv/* ${DESTDIR}${PREFIX}/include/uv/

.include "../../mk/bsd.pkg.mk"
