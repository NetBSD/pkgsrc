# $NetBSD: Makefile,v 1.3 2004/03/26 02:27:47 wiz Exp $

DISTNAME=	kdemultimedia-2.2.2
PKGREVISION=	6
CATEGORIES=	multimedia
COMMENT=	KDE multimedia tools

.include "../../x11/kde2/Makefile.kde2"

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde
DEPENDS+=	xanim>=2.80.0:../../multimedia/xanim

USE_BUILDLINK2=		YES
PTHREAD_OPTS+=		require

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
