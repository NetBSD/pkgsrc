# $NetBSD: Makefile,v 1.9 2001/04/17 11:14:05 tron Exp $

DISTNAME=	zlib-1.1.3
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.freesoftware.com/pub/infozip/zlib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	ftp://ftp.freesoftware.com/pub/infozip/zlib/index.html
COMMENT=	General purpose data compression library

BUILD_DEPENDS+=	libtool-base>=${LIBTOOL_VERSION}:../../devel/libtool-base

ONLY_FOR_PLATFORM=	SunOS-*-* # in base NetBSD system

# To avoid circular dependences we must not use "USE_LIBTOOL" but
# depend on the "libtool-base" package manually.
LIBTOOL=	${LOCALBASE}/bin/libtool
CONFIGURE_ENV+=	LIBTOOL="${LIBTOOL} ${LIBTOOL_FLAGS}"
MAKE_ENV+=	LIBTOOL="${LIBTOOL} ${LIBTOOL_FLAGS}"
MAKEFILE=	lt.mk

post-extract:
	${CP} ${FILESDIR}/lt.mk ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
