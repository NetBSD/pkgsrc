# $NetBSD: Makefile,v 1.10 2005/06/17 03:50:25 jlam Exp $

DISTNAME=		kphone-4.1.0
CATEGORIES=		net comms
MASTER_SITES=		http://www.wirlab.net/kphone/

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.wirlab.net/kphone/
COMMENT=		Graphical Voice Over Internet (VoIP) phone

WRKSRC=			${WRKDIR}/kphone


USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
CONFIGURE_ENV+=		QTDIR="${QTDIR}"

PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes

PKG_SUPPORTED_OPTIONS=	alsa
PKG_OPTIONS_VAR=	PKG_OPTIONS.kphone

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa=yes
.else
CONFIGURE_ARGS+=	--enable-alsa=no
.endif

INSTALLATION_DIRS=	bin

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/kphone/kphone ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/kphone/icons
	${INSTALL_DATA} ${WRKSRC}/icons/*.png ${PREFIX}/share/kphone/icons

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
