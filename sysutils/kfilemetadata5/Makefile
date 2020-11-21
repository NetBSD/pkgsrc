# $NetBSD: Makefile,v 1.69 2020/11/21 09:34:58 wiz Exp $

DISTNAME=	kfilemetadata-${KF5VER}
PKGNAME=	${DISTNAME:S/-/5-/}
PKGREVISION=	3
CATEGORIES=	sysutils

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Library for extracting file metadata
LICENSE=	gnu-lgpl-v2 AND gnu-lgpl-v2.1 AND gnu-lgpl-v3

.include "../../meta-pkgs/kde/kf5.mk"

USE_TOOLS+=	msgmerge pkg-config

DEPENDS+=	catdoc-[0-9]*:../../textproc/catdoc

.include "../../lang/python/tool.mk"
.include "../../archivers/karchive/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/kcoreaddons/buildlink3.mk"
.include "../../devel/ki18n/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../print/poppler-qt5/buildlink3.mk"
.include "../../sysutils/attr/buildlink3.mk"
.include "../../textproc/ebook-tools/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
