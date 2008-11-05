# $NetBSD: Makefile,v 1.1.1.1 2008/11/05 13:07:14 obache Exp $
#

DISTNAME=	json-glib-0.6.2
CATEGORIES=	textproc
MASTER_SITES=	http://folks.o-hand.com/~ebassi/sources/

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://live.gnome.org/JsonGlib
COMMENT=	JSON parser for GLib-based libraries and applications

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	json-glib.pc.in

TEST_TARGET=	check

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
