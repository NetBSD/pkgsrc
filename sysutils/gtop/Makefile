# $NetBSD: Makefile,v 1.6 2000/06/27 02:33:16 dmcmahill Exp $

DISTNAME=		gtop-1.0.9
CATEGORIES=		sysutils gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/gtop/}

MAINTAINER=		tron@netbsd.org

DEPENDS+=		gnome-core>=1.2.0:../../x11/gnome-core
DEPENDS+=		libgtop>=1.0.9:../../devel/libgtop

GNU_CONFIGURE=		yes
USE_LIBTOOL=            yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_X11BASE=		yes

.include "../../mk/bsd.pkg.mk"
