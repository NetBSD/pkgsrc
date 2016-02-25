# $NetBSD: Makefile,v 1.110 2016/02/25 15:35:30 jperkin Exp $

DISTNAME=	kdeutils-${_KDE_VERSION}
PKGREVISION=	36
COMMENT=	Utilities for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

.include "../../mk/bsd.prefs.mk"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}
MAKE_ENV+=		EXPORT_SYMBOLS_LDFLAGS=${EXPORT_SYMBOLS_LDFLAGS:Q}

USE_TOOLS+=		gtar:run

SUBST_CLASSES+=		tarexe
SUBST_STAGE.tarexe=	pre-configure
SUBST_MESSAGE.tarexe=	Use GNU tar in ark
SUBST_FILES.tarexe=	ark/ark.kcfg
SUBST_SED.tarexe=	-e 's:<default>tar</default>:<default>${TOOLS_PATH.gtar}</default>:'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=		-D__NetBSD_APM__
.endif

CONFIGURE_ENV.DragonFly+= 	ac_cv_c_long_double=no

CONFIGURE_ARGS+=	--with-snmp=no
CONFIGURE_ARGS+=	--with-pythondir=${LOCALBASE}
CONFIGURE_ENV+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 3.5.10

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
