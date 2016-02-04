# $NetBSD: Makefile,v 1.6 2016/02/04 12:13:30 wiz Exp $

DISTNAME=	gnome-sudoku-3.16.0
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-sudoku/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://wiki.gnome.org/Apps/Sudoku
COMMENT=	Number grid logic puzzle
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

BUILD_DEPENDS+=	itstool-[0-9]*:../../textproc/itstool

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.40.0
.include "../../devel/glib2/schemas.mk"
.include "../../devel/libgee/buildlink3.mk"
BUILDLINK_API_DEPENDS.qqwing+=	qqwing>=1.3.4
.include "../../games/qqwing/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_DEPMETHOD.vala:= build
BUILDLINK_API_DEPENDS.vala+=	vala>=0.27.1.30
.include "../../lang/vala/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/json-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.15.0
.include "../../x11/gtk3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
