# $NetBSD: Makefile,v 1.19 2006/02/05 23:09:18 joerg Exp $
#

DISTNAME=	koth-0.8.0
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/games/multiplayer/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/koth/
COMMENT=	The classic "shoot the other tank" artillery game, networked

GNU_CONFIGURE=	YES
CPPFLAGS+=	-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR:Q}\""

EGDIR=		${PREFIX}/share/examples/koth
CONF_FILES=	${EGDIR}/koth.cfg ${PKG_SYSCONFDIR}/koth.cfg

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/koth
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/koth
	${INSTALL_DATA} ${WRKSRC}/src/koth.cfg ${EGDIR}

.include "../../graphics/libggi/buildlink3.mk"
.include "../../graphics/libgii/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
