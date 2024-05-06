# $NetBSD: Makefile,v 1.30 2024/05/06 08:40:25 jperkin Exp $
#

DISTNAME=	koth-0.8.0
PKGREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/games/multiplayer/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/koth/
COMMENT=	The classic "shoot the other tank" artillery game, networked

PTHREAD_AUTO_VARS=	yes
GNU_CONFIGURE=		YES
CPPFLAGS+=		-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

EGDIR=		${PREFIX}/share/examples/koth
CONF_FILES=	${EGDIR}/koth.cfg ${PKG_SYSCONFDIR}/koth.cfg

INSTALLATION_DIRS+=	share/doc/koth ${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/koth
	${INSTALL_DATA} ${WRKSRC}/src/koth.cfg ${DESTDIR}${EGDIR}

.include "../../graphics/libggi/buildlink3.mk"
.include "../../graphics/libgii/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
