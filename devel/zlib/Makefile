# $NetBSD: Makefile,v 1.15.2.1 2003/06/19 00:53:09 grant Exp $

DISTNAME=	zlib-1.1.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libpng/} \
		http://www.libpng.org/pub/png/src/ \
		ftp://swrinde.nde.swri.edu/pub/png/src/ \
		http://www.gzip.org/zlib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gzip.org/zlib/
COMMENT=	General purpose data compression library

BUILD_DEPENDS+=	libtool-base>=${LIBTOOL_REQD}:../../devel/libtool-base

USE_BUILDLINK2=		# defined
HAS_CONFIGURE=		# defined
NOT_FOR_PLATFORM=	NetBSD-1.[4-9]*-* # in base NetBSD system

# To avoid circular dependences we must not use "USE_LIBTOOL" but
# depend on the "libtool-base" package manually.
#
LIBTOOL=	${LOCALBASE}/bin/libtool
PKGLIBTOOL=	${BUILDLINK_LIBTOOL}
CONFIGURE_ENV+=	LIBTOOL="${PKGLIBTOOL} ${LIBTOOL_FLAGS}"
MAKE_ENV+=	LIBTOOL="${PKGLIBTOOL} ${LIBTOOL_FLAGS}"

post-extract:
	${CP} ${FILESDIR}/lt.mk ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
