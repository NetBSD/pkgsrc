# $NetBSD: Makefile,v 1.1 2013/10/17 15:41:09 ryoon Exp $

DISTNAME=	panda-dist
PKGNAME=	klh10-2.0h
CATEGORIES=	emulators
MASTER_SITES=	http://panda.trailing-edge.com/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://panda.trailing-edge.com/
COMMENT=	PDP-10 KL10B CPU model emulator
#LICENSE=	# KLH10 Free-Fork License

DIST_SUBDIR=	${PKGNAME_NOREV}

WRKSRC=	${WRKDIR}/${DISTNAME}/klh10-2.0h

USE_TOOLS+=	pax

BUILD_DIRS=	bld/nbx86
BUILD_TARGET=	base-kl

CFLAGS+=	-DKLH10_NET_TAP_BRIDGE

INSTALL_MAKE_FLAGS+=	KLH10_HOME=${DESTDIR}${PREFIX}/share/klh10/bin

post-install:
	cd ${WRKSRC}/run; ${FIND} . -type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/share/klh10
	cd ${WRKSRC}/doc; ${FIND} . -type f \! -name '*.orig' -print | \
		pax -rw ${DESTDIR}${PREFIX}/share/klh10

.include "../../mk/bsd.pkg.mk"
