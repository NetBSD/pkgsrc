# $NetBSD: Makefile,v 1.12.2.1 2002/05/11 02:09:06 jlam Exp $

DISTNAME=	zlib-1.1.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		http://www.libpng.org/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/src/ \
		http://www.gzip.org/zlib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gzip.org/zlib/
COMMENT=	General purpose data compression library

BUILD_DEPENDS+=	libtool-base>=${LIBTOOL_VERSION}:../../devel/libtool-base

USE_BUILDLINK2_ONLY=	# defined
NOT_FOR_PLATFORM=	NetBSD-*-* # in base NetBSD system

# To avoid circular dependences we must not use "USE_LIBTOOL" but
# depend on the "libtool-base" package manually.
#
LIBTOOL=	${LOCALBASE}/bin/libtool
CONFIGURE_ENV+=	LIBTOOL="${BUILDLINK_LIBTOOL} ${LIBTOOL_FLAGS}"
MAKE_ENV+=	LIBTOOL="${BUILDLINK_LIBTOOL} ${LIBTOOL_FLAGS}"
MAKEFILE=	lt.mk

post-extract:
	${CP} ${FILESDIR}/lt.mk ${WRKSRC}

post-build: buildlink-libtool-fix

.include "../../mk/bsd.pkg.mk"
