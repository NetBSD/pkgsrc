# $NetBSD: Makefile,v 1.60 2018/11/12 03:51:16 ryoon Exp $

DISTNAME=	clutter-1.26.2
PKGREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/clutter/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Clutter
COMMENT=	Open GL based interactive canvas library
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	clutter/cally/cally.pc.in
PKGCONFIG_OVERRIDE+=	clutter/clutter.pc.in

# This requires cogl be built with EGL support, but EGL support is currently
# optional in MesaLib and not enabled in cogl, so just explicitly disable
# until this can be detected properly via various PKG_OPTIONS.
CONFIGURE_ARGS+=	--disable-egl-backend

.include "options.mk"

TEST_TARGET=	check

# Broken compat symlinks which fail "test -f" check in mk/plist/shlib-dylib.awk
# so they end up missing from PLIST.  We don't need them so just remove.
.if ${OPSYS} == "Darwin"
post-install:
	rm -f ${DESTDIR}${PREFIX}/lib/libclutter-glx-1.0.so*
.endif

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.atk+=	atk>=2.5.3
.include "../../devel/atk/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.39.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.pango+=	pango>=1.30.0
.include "../../devel/pango/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo-gobject+=	cairo-gobject>=1.14.0
.include "../../graphics/cairo-gobject/buildlink3.mk"
BUILDLINK_API_DEPENDS.cogl+=	cogl>=1.20.0
.include "../../graphics/cogl/buildlink3.mk"
BUILDLINK_API_DEPENDS.json-glib+=	json-glib>=0.12.0
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
