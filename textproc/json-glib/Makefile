# $NetBSD: Makefile,v 1.21 2014/04/20 09:36:29 obache Exp $
#

DISTNAME=	json-glib-1.0.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/json-glib/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/JsonGlib
COMMENT=	JSON parser for GLib-based libraries and applications
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake msgfmt msgmerge pkg-config xgettext

PKGCONFIG_OVERRIDE+=	json-glib.pc.in

TEST_TARGET=		check

.include "options.mk"

PRINT_PLIST_AWK+= \
	($$0 ~ /^lib\/girepository-1.0\//) || \
	($$0 ~ /^share\/gir-1.0\//) \
	{ $$0 = "$${PLIST.introspection}" $$0; } \
	($$0 ~ /^${PKGLOCALEDIR:S|/|\/|g}\/locale\//) \
	{ $$0 = "$${PLIST.nls}" $$0; }

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
