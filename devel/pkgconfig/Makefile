# $NetBSD: Makefile,v 1.14 2003/08/27 20:45:22 heinz Exp $
#

DISTNAME=	pkgconfig-0.15.0
CATEGORIES=	devel
MASTER_SITES=	http://www.freedesktop.org/software/pkgconfig/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/software/pkgconfig/
COMMENT=	System for managing library compile/link flags

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool ${WRKSRC}/glib-1.2.8/libtool
CONFIGURE_ARGS+=	--disable-threads

TEST_TARGET=		check

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
