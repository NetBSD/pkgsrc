# $NetBSD: Makefile,v 1.75 2023/11/27 11:16:40 jperkin Exp $

DISTNAME=	dconf-editor-3.38.3
PKGREVISION=	14
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dconf-editor/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/dconf
COMMENT=	GSettings editor
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c99
USE_TOOLS+=	msgfmt pkg-config

.include "../../mk/bsd.prefs.mk"
# msgfmt: unknown option -- desktop
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.msgfmt=
.endif

.include "../../devel/dconf/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.46.0
.include "../../devel/glib2/schemas.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.22.0
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
