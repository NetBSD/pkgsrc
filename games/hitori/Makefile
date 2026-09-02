# $NetBSD: Makefile,v 1.46 2026/09/02 19:02:12 wiz Exp $

DISTNAME=	hitori-44.0
PKGREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/hitori/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://gitlab.gnome.org/GNOME/hitori
COMMENT=	Logic game similar to Sudoku
LICENSE=	gnu-gpl-v3 AND cc-by-sa-v3.0

USE_TOOLS+=	msgfmt pkg-config xgettext itstool

.include "../../mk/bsd.prefs.mk"
# msgfmt: unknown option -- desktop
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.msgfmt=
.endif

PYTHON_FOR_BUILD_ONLY=	tool

BUILDLINK_DEPMETHOD.gettext-lib=	build
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/meson/build.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.22.0
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
