# $NetBSD: Makefile,v 1.32 2020/03/18 18:01:23 joerg Exp $

DISTNAME=	json-glib-1.4.4
PKGREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/json-glib/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/JsonGlib
COMMENT=	JSON parser for GLib-based libraries and applications
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake msgfmt msgmerge pkg-config xgettext

CONFIGURE_ARGS+=	--disable-man

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CC+=	-Wno-error=void-pointer-to-int-cast
CWRAPPERS_APPEND.cc+=	-Wno-error=void-pointer-to-int-cast
.endif

# workaround for build failure
# https://gitlab.gnome.org/GNOME/json-glib/issues/35
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/json-glib

.include "options.mk"

PRINT_PLIST_AWK+= \
	($$0 ~ /^lib\/girepository-1.0\//) || \
	($$0 ~ /^share\/gir-1.0\//) \
	{ $$0 = "$${PLIST.introspection}" $$0; } \
	($$0 ~ /^${PKGLOCALEDIR:S|/|\/|g}\/locale\//) \
	{ $$0 = "$${PLIST.nls}" $$0; }

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
