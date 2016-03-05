# $NetBSD: Makefile,v 1.42 2016/03/05 11:29:06 jperkin Exp $

DISTNAME=		kphone-4.2
PKGREVISION=		21
CATEGORIES=		net comms
MASTER_SITES=		http://www.wirlab.net/kphone/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/kphone
COMMENT=		Graphical Voice Over Internet (VoIP) phone

WRKSRC=			${WRKDIR}/kphone

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
CONFIGURE_ENV+=		QTDIR=${QTDIR:Q}

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

INSTALLATION_DIRS=	bin share/kphone/icons

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kphone/kphone ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/icons/*.png \
		${DESTDIR}${PREFIX}/share/kphone/icons

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
