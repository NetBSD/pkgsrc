# $NetBSD: Makefile,v 1.7 2001/10/24 22:10:56 jlam Exp $

DISTNAME=	gnome-chess-0.3.3
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-chess/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://arcavia.com/rd/gnome-chess/
COMMENT=	GNOME's graphical interface for playing chess

GNU_CONFIGURE=	yes
USE_X11BASE=	yes

.include "../../x11/gnome-core/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
