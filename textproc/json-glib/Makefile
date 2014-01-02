# $NetBSD: Makefile,v 1.19 2014/01/02 12:19:00 obache Exp $
#

DISTNAME=	json-glib-0.16.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/json-glib/0.16/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/JsonGlib
COMMENT=	JSON parser for GLib-based libraries and applications
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	json-glib.pc.in

.include "options.mk"

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.34.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
