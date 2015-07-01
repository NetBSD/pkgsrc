# $NetBSD: Makefile,v 1.24 2015/07/01 09:32:36 wiz Exp $

DISTNAME=	json-glib-1.0.4
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/json-glib/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/JsonGlib
COMMENT=	JSON parser for GLib-based libraries and applications
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake msgfmt msgmerge pkg-config xgettext

CONFIGURE_ARGS+=	--disable-man

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
