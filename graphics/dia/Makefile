# $NetBSD: Makefile,v 1.13 2003/05/02 11:55:12 wiz Exp $

DISTNAME=		dia-0.90
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/dia/0.90/}

MAINTAINER=		jmcneill@invisible.yi.org
HOMEPAGE=		http://www.lysator.liu.se/~alla/dia/
COMMENT=		program for creating diagrams of all kinds

BUILD_DEPENDS+=		bison>=1.35:../../devel/bison

USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-gnome

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../textproc/libxml/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../textproc/libunicode/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
