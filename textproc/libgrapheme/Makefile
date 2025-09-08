# $NetBSD: Makefile,v 1.3 2025/09/08 08:22:16 vins Exp $

DISTNAME=	libgrapheme-2.0.2
PKGREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	https://dl.suckless.org/libgrapheme/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://libs.suckless.org/libgrapheme/
COMMENT=	Unicode string library
LICENSE=	isc

CPPFLAGS+=		-D_DEFAULT_SOURCE

BUILDLINK_TRANSFORM+=	opt:-std=c99:-std=gnu99 # strdup(), getline()

SONAME=		${PKGBASE}.${PKGVERSION_NOREV}

NO_CONFIGURE=	yes

MAKE_FLAGS+=	PREFIX=${PREFIX} \
		MANPREFIX=${PREFIX}/${PKGMANDIR} \
		RANLIB=${RANLIB:Q} SH=${SH:Q} \
		CC=${CC:Q} CPPFLAGS=${CPPFLAGS:Q} \
		CFLAGS=${CFLAGS:Q} \
		LDFLAGS=${LDFLAGS:Q} \
		SONAME=${SONAME:Q} \
		SOFLAGS="-shared -nostdlib" \
		LDCONFIG=

.include "../../mk/bsd.pkg.mk"
