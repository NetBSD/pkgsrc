# $NetBSD: Makefile,v 1.2 2013/03/02 08:19:36 agc Exp $
#

DISTNAME=	master
PKGNAME=	libuv-20130301
CATEGORIES=	devel
MASTER_SITES=	https://github.com/joyent/libuv/archive/
EXTRACT_SUFX=	.zip

MAINTAINER=	agc@pkgsrc.org
HOMEPAGE=	http://nikhilm.github.com/uvbook/
COMMENT=	Asynchronous event library, platform layer of node.js
LICENSE=	joyent

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/libuv-master

USE_TOOLS+=	gmake
AUTO_MKDIRS=	yes

HEADERS=	ngx-queue.h stdint-msvc2008.h tree.h uv-bsd.h uv-darwin.h
HEADERS+=	uv-linux.h uv-sunos.h uv-unix.h uv-win.h

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/uv.h ${DESTDIR}${PREFIX}/include/uv.h
	for f in ${HEADERS}; do						\
		${INSTALL_DATA} ${WRKSRC}/include/uv-private/$$f ${DESTDIR}${PREFIX}/include/uv-private/$$f; \
	done
	${INSTALL_LIB} ${WRKSRC}/libuv.a ${DESTDIR}${PREFIX}/lib/libuv.a

.include "../../mk/bsd.pkg.mk"
