# $NetBSD: Makefile,v 1.9 2002/09/21 10:40:07 jlam Exp $
#

DISTNAME=	gnome-objc-1.0.40
PKGREVISION=	1
CATEGORIES=	devel lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-objc/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Objective C API for gnome and gtk

USE_BUILDLINK2=		YES
USE_X11=		YES
PTHREAD_OPTS+=		require

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		OBJC="${CC}"

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
