# $NetBSD: Makefile,v 1.72 2024/05/29 16:33:47 adam Exp $

DISTNAME=	subtitleeditor-0.54.0
PKGREVISION=	25
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=kitone/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://kitone.github.io/subtitleeditor/
COMMENT=	GTK+ tool to create or edit subtitles
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	pkg-config perl gmake
USE_TOOLS+=	intltool msgfmt msgmerge xgettext
USE_LANGUAGES=	c c++14

USE_CXX_FEATURES+=	c++14

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/gstreamermm1/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../x11/gtkmm3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
