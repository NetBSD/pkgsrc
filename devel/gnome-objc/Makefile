# $NetBSD: Makefile,v 1.14 2003/07/17 21:30:50 grant Exp $
#

DISTNAME=	gnome-objc-1.0.40
PKGREVISION=	3
CATEGORIES=	devel lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-objc/1.0/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Objective C API for gnome and gtk

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
PTHREAD_OPTS+=		require

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		OBJC="${CC}"

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
