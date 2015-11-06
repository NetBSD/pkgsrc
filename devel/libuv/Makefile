# $NetBSD: Makefile,v 1.6 2015/11/06 09:19:40 wiz Exp $

DISTNAME=	libuv-1.7.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libuv/}

MAINTAINER=	agc@pkgsrc.org
HOMEPAGE=	http://github.com/libuv/libuv/
COMMENT=	Cross-platform asychronous I/O
LICENSE=	mit AND 2-clause-bsd AND isc AND modified-bsd

GITHUB_TAG=	v${PKGVERSION_NOREV}

USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake pkg-config
GNU_CONFIGURE=	yes

HEADERS=	uv-aix.h uv-bsd.h uv-darwin.h uv-linux.h uv-sunos.h	\
		uv-unix.h uv-win.h

pre-configure:
	${RUN} cd ${WRKSRC} && ${SH} ./autogen.sh

post-install:
.for file in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/include/${file} ${DESTDIR}${PREFIX}/include
.endfor

.include "../../mk/bsd.pkg.mk"
