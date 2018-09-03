# $NetBSD: Makefile,v 1.45 2018/09/03 10:50:18 wiz Exp $

DISTNAME=	dconf-editor-3.22.3
PKGREVISION=	6
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dconf-editor/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/dconf
COMMENT=	gsettings editor
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake intltool msgfmt

BUILDLINK_API_DEPENDS.dconf+=	dconf>=0.25.1
.include "../../devel/dconf/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.46.0
.include "../../devel/glib2/schemas.mk"
BUILDLINK_DEPMETHOD.vala= build
BUILDLINK_API_DEPENDS.vala+=	vala>=0.33.1
.include "../../lang/vala/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.22.0
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
