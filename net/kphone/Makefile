# $NetBSD: Makefile,v 1.5 2004/12/04 23:09:07 jlam Exp $

DISTNAME=		kphone-4.0.5
CATEGORIES=		net comms
MASTER_SITES=		http://www.wirlab.net/kphone/

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.wirlab.net/kphone/
COMMENT=		Graphical Voice Over Internet (VoIP) phone

WRKSRC=			${WRKDIR}/kphone

USE_BUILDLINK3=		yes

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
CONFIGURE_ENV=		QTDIR="${QTDIR}"

PTHREAD_OPTS+=		require
PTHREAD_AUTO_VARS=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/kphone/kphone ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/kphone/icons
	${INSTALL_DATA} ${WRKSRC}/icons/*.png ${PREFIX}/share/kphone/icons

.include "../../x11/qt3-libs/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
