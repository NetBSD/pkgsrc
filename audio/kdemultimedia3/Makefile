# $NetBSD: Makefile,v 1.1.1.1.2.2 2002/06/23 18:37:56 jlam Exp $

DISTNAME=	kdemultimedia-3.0.1
CATEGORIES=	audio
COMMENT=	Audio tools for the KDE integrated X11 desktop

.include "../../x11/kde3/Makefile.kde3"

DEPENDS+=	xanim>=2.80.0:../../graphics/xanim

USE_BUILDLINK_ONLY=	YES

#USE_CONFIG_WRAPPER=     yes                             # $GTK_CONFIG
#CONFIGURE_ENV+=		ac_cv_path_kde_artsplug_compiles="${ARTSC_CONFIG}"

USE_PTHREAD=            native pth-syscall
.include "../../mk/bsd.prefs.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} == "none"
CONFIGURE_ARGS+=        --disable-threading
.endif

.if ${OPSYS} == "NetBSD"
LIBS=			-Wl,--export-dynamic
.endif

.include "../../mk/pthread.buildlink.mk"
.include "../../audio/arts/buildlink.mk"
.include "../../x11/kde3/buildlink.mk"
.include "../../x11/kdebase3/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
