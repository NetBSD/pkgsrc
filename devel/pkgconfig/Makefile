# $NetBSD: Makefile,v 1.19 2004/10/13 19:12:22 reed Exp $
#

DISTNAME=	pkgconfig-0.15.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.freedesktop.org/software/pkgconfig/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/Software/pkgconfig
COMMENT=	System for managing library compile/link flags

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
CONFIGURE_ARGS+=	--disable-threads

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "IRIX"
# configure bails out in subdir after re-parsing the cache
CONFIGURE_ARGS+=	--cache-file=/dev/null
.endif

TEST_TARGET=		check

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
