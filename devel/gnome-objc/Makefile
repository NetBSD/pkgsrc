# $NetBSD: Makefile,v 1.8 2002/08/01 05:48:09 jlam Exp $
#

DISTNAME=	gnome-objc-1.0.40
PKGREVISION=	1
CATEGORIES=	devel lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-objc/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Objective C API for gnome and gtk

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
PTHREAD_OPTS+=	require

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

CONFIGURE_ENV+=	OBJC="${CC}"

.include "../../x11/gnome-libs/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
