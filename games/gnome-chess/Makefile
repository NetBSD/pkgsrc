# $NetBSD: Makefile,v 1.4 2001/09/27 23:18:06 jlam Exp $

DISTNAME=	gnome-chess-0.2.4
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/gnome-chess/}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://arcavia.com/rd/gnome-chess/
COMMENT=	GNOME's graphical interface for playing chess

DEPENDS+=	gnome-core-[0-9]*:../../x11/gnome-core

GNU_CONFIGURE=	yes
USE_X11BASE=	yes

.include "../../mk/bsd.pkg.mk"
