# $NetBSD: Makefile,v 1.10 2003/07/13 13:51:51 wiz Exp $
#

DISTNAME=	koth-0.8.0
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://savannah.nongnu.org/download/koth/default.pkg/0.8.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.nongnu.org/koth/
COMMENT=	The classic "shoot the other tank" artillery game, networked

USE_BUILDLINK2=	YES
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

.include "../../graphics/libggi/buildlink2.mk"
.include "../../graphics/libgii/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
