# $NetBSD: Makefile,v 1.2 2024/05/29 16:34:27 adam Exp $

DISTNAME=	kfilemetadata-${KF6VER}
PKGREVISION=	1
CATEGORIES=	sysutils

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Library for extracting file metadata
LICENSE=	gnu-lgpl-v2 AND gnu-lgpl-v2.1 AND gnu-lgpl-v3

USE_CXX_FEATURES+=	filesystem

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	msgmerge pkg-config

DEPENDS+=	catdoc-[0-9]*:../../textproc/catdoc

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "SunOS"
.include "../../sysutils/attr/buildlink3.mk"
.endif

.include "../../lang/python/tool.mk"
.include "../../archivers/kf6-karchive/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
#.include "../../graphics/kdegraphics-mobipocket/buildlink3.mk"
.include "../../multimedia/ffmpeg6/buildlink3.mk"
.include "../../print/poppler-qt6/buildlink3.mk"
.include "../../textproc/ebook-tools/buildlink3.mk"
.include "../../textproc/kf6-kcodecs/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
