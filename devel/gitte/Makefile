# $NetBSD: Makefile,v 1.2 2026/09/02 19:01:25 wiz Exp $

DISTNAME=	gitte-0.7.0
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	-https://codeberg.org/ckruse/Gitte/archive/0.7.0.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/ckruse/Gitte/
COMMENT=	Git client for the GNOME desktop
LICENSE=	gnu-agpl-v3

WRKSRC=		${WRKDIR}/gitte

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# The program tries to compile gettext if it does not find it
# It checks environment variables, so we have to set them
MAKE_ENV+=	GETTEXT_LIB_DIR=${BUILDLINK_PREFIX.gettext}/lib
MAKE_ENV+=	GETTEXT_INCLUDE_DIR=${BUILDLINK_PREFIX.gettext}/include
MAKE_ENV+=	GETTEXT_BIN_DIR=${TOOLBASE}/bin

RUSTFLAGS+=	-C link-arg=${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.gtk4}/lib

.include "cargo-depends.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
# meson checks for update-desktop-database
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
