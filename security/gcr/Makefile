# $NetBSD: Makefile,v 1.39 2024/10/14 15:27:26 nia Exp $

DISTNAME=	gcr-3.40.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Library for crypto UI and related tasks
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4
DEPENDS+=	gnupg2-[0-9]*:../../security/gnupg2

USE_TOOLS+=	gdbus-codegen intltool msgfmt perl pkg-config readlink
TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gck
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/gck

LDFLAGS.SunOS+=	-lsocket

PKGCONFIG_OVERRIDE+=	gck-1.pc.in
PKGCONFIG_OVERRIDE+=	gcr-base-3.pc.in
PKGCONFIG_OVERRIDE+=	gcr-ui.pc.in
PKGCONFIG_OVERRIDE+=	gcr-3.pc.in

REPLACE_PYTHON=		meson_post_install.py

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/p11-kit/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
