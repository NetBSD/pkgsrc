# $NetBSD: Makefile,v 1.7 2002/09/01 00:38:08 mjl Exp $

DISTNAME=		dia-0.90
# PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/dia/}

MAINTAINER=		jmcneill@invisible.yi.org
HOMEPAGE=		http://www.lysator.liu.se/~alla/dia/
COMMENT=		program for creating diagrams of all kinds

BUILD_DEPENDS+=		bison>=1.35:../../devel/bison
BUILDLINK_DEPENDS.gnome_libs=	gnome-libs>=1.4.1.2nb1:../../x11/gnome-libs
BUILDLINK_DEPENDS.gdk-pixbuf=	gdk-pixbuf>=0.7.0:../../graphics/gdk-pixbuf

USE_X11=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	YES
USE_BUILDLINK2=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-gnome

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../textproc/libunicode/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
