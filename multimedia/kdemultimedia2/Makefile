# $NetBSD: Makefile,v 1.5 2004/10/03 00:13:02 tv Exp $

DISTNAME=	kdemultimedia-2.2.2
PKGREVISION=	7
CATEGORIES=	multimedia
COMMENT=	KDE multimedia tools

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde
DEPENDS+=	xanim>=2.80.0:../../multimedia/xanim

USE_BUILDLINK3=		YES
PTHREAD_OPTS+=		require

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../x11/kde2/kde2.mk"
.include "../../x11/kdebase2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
