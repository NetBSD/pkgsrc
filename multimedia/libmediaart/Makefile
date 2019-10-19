# $NetBSD: Makefile,v 1.2 2019/10/19 09:44:18 nia Exp $

DISTNAME=	libmediaart-1.9.4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libmediaart/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/libmediaart
COMMENT=	Library for managing, extracting, and handling media art caches
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	pkg-config gmake

CONFIGURE_ARGS+=	--disable-qt
CONFIGURE_ARGS+=	--disable-unit-tests

PKGCONFIG_OVERRIDE+=	libmediaart.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
