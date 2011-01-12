# $NetBSD: Makefile,v 1.8 2011/01/12 09:02:57 obache Exp $
#

DISTNAME=	json-glib-0.12.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/json-glib/0.12/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://live.gnome.org/JsonGlib
COMMENT=	JSON parser for GLib-based libraries and applications
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	json-glib.pc.in

TEST_TARGET=	check

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
