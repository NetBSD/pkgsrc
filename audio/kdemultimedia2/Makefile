# $NetBSD: Makefile,v 1.12.4.1 2002/10/24 16:59:49 wiz Exp $

DISTNAME=	kdemultimedia-2.2.2
PKGREVISION=	1
CATEGORIES=	audio
COMMENT=	KDE audio tools

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde
DEPENDS+=	xanim>=2.80.0:../../graphics/xanim

USE_BUILDLINK_ONLY=	YES
PTHREAD_OPTS+=		require

CONFIGURE_ENV+=		ac_cv_path_kde_artsplug_compiles="${ARTSCCONFIG}"

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
