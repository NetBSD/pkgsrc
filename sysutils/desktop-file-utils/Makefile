# $NetBSD: Makefile,v 1.55 2026/09/02 19:04:26 wiz Exp $

DISTNAME=	desktop-file-utils-0.28
PKGREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://freedesktop.org/software/desktop-file-utils/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/desktop-file-utils
COMMENT=	Utilities to manage desktop entries
LICENSE=	gnu-gpl-v2

USE_CC_FEATURES=	c11

USE_TOOLS+=	pkg-config

FILES_SUBST+=	APPLICATIONS_PATH="${PREFIX}/share/applications"
FILES_SUBST+=	UPDATE_DESKTOPDB="${PREFIX}/bin/update-desktop-database"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/update-desktop-database.c
SUBST_VARS.paths=	LOCALBASE

PRINT_PLIST_AWK+=	/^share\/applications\/mimeinfo.cache$$/ \
			{ print "@comment in INSTALL script: " $$0; \
			  next; }

PYTHON_FOR_BUILD_ONLY=	tool

BUILDLINK_API_DEPENDS.glib2+=   glib2>=2.26.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
