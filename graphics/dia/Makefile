# $NetBSD: Makefile,v 1.1.1.1 2000/10/17 02:09:55 hubertf Exp $

DISTNAME=		dia-0.86
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/dia/}

MAINTAINER=		jmcneill@invisible.yi.org
HOMEPAGE=		http://www.lysator.liu.se/~alla/dia/

DEPENDS+=		gnome-libs>=1.2.3:../../x11/gnome-libs
DEPENDS+=		gnome-print>=0.20:../../print/gnome-print
DEPENDS+=		libxml>=1.8.9:../../textproc/libxml
DEPENDS+=		gdk-pixbuf>=0.8.0nb1:../../graphics/gdk-pixbuf

USE_X11=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gnome --enable-gnome-print

.include "../../mk/bsd.pkg.mk"
