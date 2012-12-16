# $NetBSD: Makefile,v 1.91 2012/12/16 01:52:25 obache Exp $

DISTNAME=	kdeutils-${_KDE_VERSION}
PKGREVISION=	22
COMMENT=	Utilities for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

.include "../../mk/bsd.prefs.mk"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}
MAKE_ENV+=		EXPORT_SYMBOLS_LDFLAGS=${EXPORT_SYMBOLS_LDFLAGS:Q}

DEPENDS+=	gtar-base>=1.13.25:../../archivers/gtar-base

EVAL_PREFIX+=		PREFIX.gtar=gtar
PREFIX.gtar_DEFAULT=	${LOCALBASE}

SUBST_CLASSES+=		tarexe
SUBST_STAGE.tarexe=	pre-configure
SUBST_MESSAGE.tarexe=	Use GNU tar in ark
SUBST_FILES.tarexe=	ark/ark.kcfg
SUBST_SED.tarexe=	-e 's:<default>tar</default>:<default>${PREFIX.gtar}/bin/gtar</default>:'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && exists(/usr/include/machine/apmvar.h)
CPPFLAGS+=             -D__NetBSD_APM__
.endif

.if ${OPSYS} == "DragonFly"
CONFIGURE_ENV+= 	ac_cv_c_long_double=no
.endif

CONFIGURE_ARGS+=	--with-snmp=no
CONFIGURE_ARGS+=	--with-pythondir=${LOCALBASE}
CONFIGURE_ENV+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}

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
