# $NetBSD: Makefile,v 1.17 2024/05/29 16:31:24 adam Exp $

DISTNAME=	qtspeech-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtspeech-${QTVERSION}
PKGREVISION=	1
COMMENT=	Qt6 module for text to speech
CATEGORIES=	audio
LICENSE=	gnu-gpl-v3

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	flite

.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	-no-flite
.else
PLIST.flite=		yes
CONFIGURE_ARGS+=	-no-flite-alsa
.endif

.include "../../x11/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6TextToSpeech.pc

.if ${OPSYS} != "Linux"
.include "../../audio/flite/buildlink3.mk"
.endif
.include "../../audio/speech-dispatcher/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../multimedia/qt6-qtmultimedia/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
