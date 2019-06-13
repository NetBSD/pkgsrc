# $NetBSD: Makefile,v 1.28 2019/06/13 09:45:17 wiz Exp $

DISTNAME=	json-glib-1.4.4
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/json-glib/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/JsonGlib
COMMENT=	JSON parser for GLib-based libraries and applications
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake msgfmt msgmerge pkg-config xgettext

CONFIGURE_ARGS+=	--disable-man

# workaround for build failure
# https://gitlab.gnome.org/GNOME/json-glib/issues/35
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/json-glib

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ninja -C output test

.include "options.mk"

PRINT_PLIST_AWK+= \
	($$0 ~ /^lib\/girepository-1.0\//) || \
	($$0 ~ /^share\/gir-1.0\//) \
	{ $$0 = "$${PLIST.introspection}" $$0; } \
	($$0 ~ /^${PKGLOCALEDIR:S|/|\/|g}\/locale\//) \
	{ $$0 = "$${PLIST.nls}" $$0; }

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/py-meson/build.mk"
.include "../../mk/bsd.pkg.mk"
