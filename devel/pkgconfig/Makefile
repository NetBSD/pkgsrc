# $NetBSD: Makefile,v 1.11 2003/06/02 01:20:19 jschauma Exp $
#

DISTNAME=	pkgconfig-0.15.0
CATEGORIES=	devel
MASTER_SITES=	http://www.freedesktop.org/software/pkgconfig/releases/

MAINTAINER=	tech-pkg@netbsd.org
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
