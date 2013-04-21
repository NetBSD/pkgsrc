# $NetBSD: Makefile,v 1.17 2013/04/21 14:04:20 rodent Exp $
#

DISTNAME=	json-glib-0.16.0
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

.include "../../mk/pthread.buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
