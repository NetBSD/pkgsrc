# $NetBSD: Makefile,v 1.5 2000/06/02 13:29:40 tron Exp $

DISTNAME=		gtop-1.0.9
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gtop/}

MAINTAINER=		tron@netbsd.org

DEPENDS+=		gnome-core>=1.2.0:../../x11/gnome-core
DEPENDS+=		libgtop>=1.0.9:../../devel/libgtop

GNU_CONFIGURE=		yes
USE_X11BASE=		yes

.include "../../mk/bsd.pkg.mk"
