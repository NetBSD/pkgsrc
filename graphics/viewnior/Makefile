# $NetBSD: Makefile,v 1.46 2023/11/14 14:02:12 wiz Exp $

DISTNAME=	viewnior-1.7
PKGREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=hellosiyan/}
GITHUB_PROJECT=	Viewnior
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://siyanpanayotov.com/project/viewnior
COMMENT=	Fast and simple image viewer
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/Viewnior-${DISTNAME}

USE_TOOLS+=	pkg-config msgfmt xgettext
USE_LANGUAGES=	c c++

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/meson/build.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../databases/shared-mime-info/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
