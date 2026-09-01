# $NetBSD: Makefile,v 1.56 2026/09/01 21:28:14 fox Exp $

DISTNAME=	foliate-3.3.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=johnfactotum/}
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
COMMENT=	Simple and modern GTK eBook viewer
HOMEPAGE=	https://johnfactotum.github.io/foliate/
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config msgfmt xgettext

RUN_DEPENDS+=	gjs>=1.82.0:../../lang/gjs

GITHUB_SUBMODULES=	johnfactotum foliate-js 052123beafed921a9a2a45ef6330c235289a634e src/foliate-js

GLIB_SCHEMAS=	com.github.johnfactotum.Foliate.gschema.xml

INSTALLATION_DIRS+=	libexec/foliate

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
BUILDLINK_API_DEPENDS.libadwaita+=	libadwaita>=1.8
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.webkit-gtk60+=	webkit-gtk60>=2.40.1
.include "../../www/webkit-gtk60/buildlink3.mk"
.include "../../lang/gjs/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
