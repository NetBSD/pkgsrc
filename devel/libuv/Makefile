# $NetBSD: Makefile,v 1.33 2018/04/23 07:03:12 adam Exp $

DISTNAME=	libuv-1.20.2
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

HEADERS=	uv-aix.h uv-bsd.h uv-darwin.h uv-linux.h uv-sunos.h \
		uv-unix.h uv-win.h pthread-barrier.h

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MSunOS-5.[0-9]-*) || \
    !empty(MACHINE_PLATFORM:MSunOS-5.10-*)
CFLAGS+=	-DSUNOS_NO_IFADDRS
.endif

pre-configure:
	${RUN} cd ${WRKSRC} && ${SH} ./autogen.sh

post-install:
.for file in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/include/${file} ${DESTDIR}${PREFIX}/include
.endfor

.include "../../mk/bsd.pkg.mk"
