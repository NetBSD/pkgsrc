# $NetBSD: Makefile,v 1.9 2002/11/04 19:29:37 wiz Exp $
#

DISTNAME=	pkgconfig-0.14.0
CATEGORIES=	devel
MASTER_SITES=	http://www.freedesktop.org/software/pkgconfig/releases/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.freedesktop.org/software/pkgconfig/
COMMENT=	system for managing library compile/link flags

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool ${WRKSRC}/glib-1.2.8/libtool
CONFIGURE_ARGS+=	--disable-threads

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/pkgconfig

.include "../../mk/bsd.pkg.mk"
