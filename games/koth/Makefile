# $NetBSD: Makefile,v 1.13 2004/10/03 00:14:45 tv Exp $
#

DISTNAME=	koth-0.8.0
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://savannah.nongnu.org/download/koth/default.pkg/0.8.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/koth/
COMMENT=	The classic "shoot the other tank" artillery game, networked

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES
CPPFLAGS+=	-DPKG_SYSCONFDIR=\"\\\"${PKG_SYSCONFDIR:Q}\\\"\"

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
