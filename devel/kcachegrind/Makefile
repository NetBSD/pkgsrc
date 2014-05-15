# $NetBSD: Makefile,v 1.6 2014/05/15 14:41:46 adam Exp $

DISTNAME=	kcachegrind-${_KDE_VERSION}
PKGREVISION=	3
CATEGORIES=	devel
COMMENT=	Visualization of Performance Profiling Data

.include "../../meta-pkgs/kde4/Makefile.kde4"

REPLACE_PERL+= \
	converters/dprof2calltree \
	converters/memprof2calltree \
	converters/op2calltree

# REPLACE_PHP+= converters/pprof2calltree
SUBST_CLASSES+=		php
SUBST_MESSAGE.php=	Fixing PHP path
SUBST_STAGE.php=	post-configure
SUBST_FILES.php=	converters/pprof2calltree
SUBST_SED.php=		-e 's,/usr/bin/env php,${PREFIX}/bin/php,'

REPLACE_PYTHON+= \
	converters/hotshot2calltree

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
