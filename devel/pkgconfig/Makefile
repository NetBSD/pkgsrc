# $NetBSD: Makefile,v 1.8 2002/09/29 22:35:21 dmcmahill Exp $
#

DISTNAME=	pkgconfig-0.13.0
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
