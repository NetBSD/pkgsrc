# $NetBSD: Makefile,v 1.4 2001/08/26 01:27:14 mjl Exp $

DISTNAME=		dia-0.88.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/dia/}

MAINTAINER=		jmcneill@invisible.yi.org
HOMEPAGE=		http://www.lysator.liu.se/~alla/dia/
COMMENT=		program for creating diagrams of all kinds

DEPENDS+=		gnome-libs>=1.2.3:../../x11/gnome-libs
DEPENDS+=		libxml>=1.8.9:../../textproc/libxml
DEPENDS+=		gnome-print>=0.20:../../print/gnome-print
DEPENDS+=		gdk-pixbuf>=0.8.0nb1:../../graphics/gdk-pixbuf

USE_X11=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		YES
USE_BUILDLINK_ONLY=	YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gnome --enable-gnome-print

.include "../../graphics/gdk-pixbuf/buildlink.mk"
.include "../../x11/gnome-libs/buildlink.mk"
.include "../../textproc/libxml/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
