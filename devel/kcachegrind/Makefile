# $NetBSD: Makefile,v 1.76 2024/05/29 16:32:04 adam Exp $

DISTNAME=	kcachegrind-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	devel

HOMEPAGE=	https://kde.org/applications/development/kcachegrind/
COMMENT=	Visualization of Performance Profiling Data
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge perl:run

REPLACE_PERL+=	converters/dprof2calltree
REPLACE_PERL+=	converters/memprof2calltree
REPLACE_PERL+=	converters/op2calltree

REPLACE_PYTHON+=	converters/hotshot2calltree.in

# REPLACE_PHP+= converters/pprof2calltree
SUBST_CLASSES+=		php
SUBST_MESSAGE.php=	Fixing PHP path
SUBST_STAGE.php=	post-configure
SUBST_FILES.php=	converters/pprof2calltree
SUBST_SED.php=		-e 's,/usr/bin/env php,${PREFIX}/bin/php,'

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"

.include "../../devel/kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
