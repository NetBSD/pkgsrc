# $NetBSD: Makefile,v 1.2 2004/10/03 00:17:53 tv Exp $
#

DISTNAME=		kphone-4.0.3
PKGREVISION=	1
CATEGORIES=		net comms
MASTER_SITES=		http://www.wirlab.net/kphone/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.wirlab.net/kphone/
COMMENT=		Graphical Voice Over Internet (VoIP) phone

WRKSRC=			${WRKDIR}/kphone

USE_BUILDLINK3=		yes

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
CONFIGURE_ENV=		QTDIR="${QTDIR}"

PTHREAD_OPTS+=		require

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/kphone/kphone ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/kphone/icons
	${INSTALL_DATA} ${WRKSRC}/icons/*.png ${PREFIX}/share/kphone/icons

.include "../../x11/qt3-libs/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
