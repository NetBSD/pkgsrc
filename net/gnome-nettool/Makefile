# $NetBSD: Makefile,v 1.51 2022/08/11 05:09:09 gutteridge Exp $

DISTNAME=	gnome-nettool-3.8.1
PKGREVISION=	8
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-nettool/3.8/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/gnome-nettool
COMMENT=	GNOME interface for various network tools
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	libxml2-[0-9]*:../../textproc/libxml2
TOOL_DEPENDS+=	p5-XML-LibXML>=1.58:../../textproc/p5-XML-LibXML

GNU_CONFIGURE=	yes

USE_TOOLS+=	pkg-config perl gmake itstool
USE_TOOLS+=	intltool msgfmt msgmerge xgettext

.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../sysutils/libgtop/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
