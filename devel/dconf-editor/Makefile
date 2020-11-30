# $NetBSD: Makefile,v 1.57 2020/11/30 00:03:47 gutteridge Exp $

DISTNAME=	dconf-editor-3.38.2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dconf-editor/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/dconf
COMMENT=	gsettings editor
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c99
USE_TOOLS+=	msgfmt pkg-config

# Requires --desktop in msgfmt.
_TOOLS_USE_PKGSRC.msgfmt=	yes

.include "../../devel/dconf/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.46.0
.include "../../devel/glib2/schemas.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
BUILDLINK_DEPMETHOD.vala= build
BUILDLINK_API_DEPENDS.vala+=	vala>=0.40.0
.include "../../lang/vala/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.22.0
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
