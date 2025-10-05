# $NetBSD: Makefile,v 1.4 2025/10/05 19:25:50 js Exp $

DISTNAME=	libadapta-1.5.0
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=xapp-project/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/xapp-project/libadapta/
COMMENT=	libAdwaita with theme support and a few extras
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	sassc-[0-9]*:../../www/sassc

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config

.include "../../devel/meson/build.mk"
.include "../../devel/appstream/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
