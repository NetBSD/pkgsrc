# $NetBSD: Makefile,v 1.6 2002/09/29 13:03:43 wiz Exp $
#

DISTNAME=	pkgconfig-0.12.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.freedesktop.org/software/pkgconfig/releases/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.freedesktop.org/software/pkgconfig/
COMMENT=	system for managing library compile/link flags

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool ${WRKSRC}/glib-1.2.8/libtool

PTHREAD_OPTS+=		require

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/pkgconfig

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
