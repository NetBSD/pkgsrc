# $NetBSD: Makefile,v 1.91 2026/02/06 10:04:29 wiz Exp $

DISTNAME=	kcachegrind-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/applications/development/kcachegrind/
COMMENT=	Visualization of Performance Profiling Data
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge perl:run

REPLACE_PERL+=	converters/dprof2calltree
REPLACE_PERL+=	converters/memprof2calltree
REPLACE_PERL+=	converters/op2calltree

REPLACE_PYTHON+=	converters/hotshot2calltree.in

REPLACE_PHP+=	converters/pprof2calltree

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
