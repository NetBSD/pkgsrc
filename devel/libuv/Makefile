# $NetBSD: Makefile,v 1.1.1.1 2013/03/02 07:43:40 agc Exp $
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

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/uv.h ${DESTDIR}${PREFIX}/include/uv.h
	${INSTALL_LIB} ${WRKSRC}/libuv.a ${DESTDIR}${PREFIX}/lib/libuv.a

.include "../../mk/bsd.pkg.mk"
