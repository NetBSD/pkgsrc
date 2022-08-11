# $NetBSD: Makefile,v 1.44 2022/08/11 05:08:27 gutteridge Exp $

DISTNAME=	gnome-sudoku-40.2
PKGREVISION=	6
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-sudoku/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://wiki.gnome.org/Apps/Sudoku
COMMENT=	Number grid logic puzzle
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++11
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt pkg-config itstool

PYTHON_FOR_BUILD_ONLY=    tool
.include "../../lang/python/tool.mk"

# Requires --desktop in msgfmt.
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.msgfmt=
.endif

post-extract:
	cd ${WRKSRC}/help/C && ${CHMOD} 0644 *.page legal.xml figures/*.png

REPLACE_PYTHON+=	build-aux/post_install.py

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.40.0
.include "../../devel/glib2/schemas.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../devel/meson/build.mk"
BUILDLINK_API_DEPENDS.qqwing+=	qqwing>=1.3.4
.include "../../games/qqwing/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_DEPMETHOD.vala:= build
.include "../../lang/vala/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/json-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.24.0
.include "../../x11/gtk3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
