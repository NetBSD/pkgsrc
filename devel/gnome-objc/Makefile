# $NetBSD: Makefile,v 1.20 2005/04/11 21:45:24 tv Exp $

DISTNAME=	gnome-objc-1.0.40
PKGREVISION=	5
CATEGORIES=	devel lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-objc/1.0/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Objective C API for gnome and gtk

USE_LANGUAGES=		c objc
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
PTHREAD_OPTS+=		require

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

GCC_REQD+=		3.0

.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
