# $NetBSD: Makefile,v 1.9 2001/12/14 15:54:44 skrll Exp $

DISTNAME=	kdemultimedia-2.2.2
CATEGORIES=	audio
COMMENT=	KDE audio tools

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb1:../../x11/qt2-designer-kde
DEPENDS+=	xanim>=2.80.0:../../graphics/xanim

BUILDLINK_DEPENDS.pth=	pth>=1.4.0
USE_BUILDLINK_ONLY=	YES

CONFIGURE_ENV+=		ac_cv_path_kde_artsplug_compiles="${ARTSCCONFIG}"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
LIBS=			-Wl,--export-dynamic
.endif

.include "../../devel/pth/buildlink.mk"
.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdebase2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
