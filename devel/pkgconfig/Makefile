# $NetBSD: Makefile,v 1.15 2004/01/05 20:52:10 jlam Exp $
#

DISTNAME=	pkgconfig-0.15.0
CATEGORIES=	devel
MASTER_SITES=	http://www.freedesktop.org/software/pkgconfig/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.freedesktop.org/software/pkgconfig/
COMMENT=	System for managing library compile/link flags

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool ${WRKSRC}/glib-1.2.8/libtool
CONFIGURE_ARGS+=	--disable-threads

TEST_TARGET=		check

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
