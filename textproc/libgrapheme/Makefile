# $NetBSD: Makefile,v 1.1 2025/07/26 06:36:33 vins Exp $

DISTNAME=	libgrapheme-2.0.2
CATEGORIES=	textproc devel
MASTER_SITES=	https://dl.suckless.org/libgrapheme/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://libs.suckless.org/libgrapheme/
COMMENT=	Unicode string library
LICENSE=	isc

FORCE_C_STD=	c99

CPPFLAGS+=	-D_DEFAULT_SOURCE

SONAME=		${PKGBASE}.${PKGVERSION_NOREV}

NO_CONFIGURE=	yes

MAKE_FLAGS+=	PREFIX=${PREFIX} \
		MANPREFIX=${PREFIX}/${PKGMANDIR} \
		RANLIB=${RANLIB:Q} SH=${SH:Q} \
		CC=${CC:Q} CPPFLAGS=${CPPFLAGS:Q} \
		CFLAGS=${CFLAGS:Q} \
		LDFLAGS=${LDFLAGS:Q} \
		SONAME=${SONAME:Q} \
		SOFLAGS="-shared -nostdlib -Wl,--soname=${SONAME}" \
		LDCONFIG=

.include "../../mk/bsd.pkg.mk"
