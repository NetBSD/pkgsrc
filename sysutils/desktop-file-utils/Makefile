# $NetBSD: Makefile,v 1.47 2022/08/09 12:08:33 jperkin Exp $

DISTNAME=	desktop-file-utils-0.26
PKGREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://freedesktop.org/software/desktop-file-utils/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/desktop-file-utils
COMMENT=	Utilities to manage desktop entries
LICENSE=	gnu-gpl-v2

# cc1: error: unrecognized command line option "-std=gnu11"
GCC_REQD+=	4.7

USE_TOOLS+=		pkg-config

FILES_SUBST+=		APPLICATIONS_PATH="${PREFIX}/share/applications"
FILES_SUBST+=		UPDATE_DESKTOPDB="${PREFIX}/bin/update-desktop-database"

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/update-desktop-database.c
SUBST_VARS.paths=	LOCALBASE

PRINT_PLIST_AWK+=	/^share\/applications\/mimeinfo.cache$$/ \
				{ print "@comment in INSTALL script: " $$0; \
				  next; }

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
