# $NetBSD: Makefile,v 1.4 2019/08/11 13:22:46 wiz Exp $

DISTNAME=		gcr-3.28.0
PKGREVISION=		4
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gcr/3.28/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnome.org/
COMMENT=		Library for crypto UI and related tasks
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
BUILD_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config

CONFIGURE_ARGS+=	--enable-vala

PKGCONFIG_OVERRIDE+=	gck-1.pc.in
PKGCONFIG_OVERRIDE+=	gcr-base-3.pc.in
PKGCONFIG_OVERRIDE+=	gcr-ui.pc.in
PKGCONFIG_OVERRIDE+=	gcr-3.pc.in

TEST_TARGET=		check

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/p11-kit/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
