# $NetBSD: Makefile,v 1.9 2002/07/17 13:11:44 rh Exp $

DISTNAME=	gnome-chess-0.3.3
PKGREVISION=	2
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-chess/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://arcavia.com/rd/gnome-chess/
COMMENT=	GNOME's graphical interface for playing chess

GNU_CONFIGURE=	yes
USE_X11BASE=	yes
CONFIGURE_ARGS+=--localstatedir=${X11PREFIX}/var/lib

.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
