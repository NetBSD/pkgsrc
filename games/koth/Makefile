# $NetBSD: Makefile,v 1.8 2003/04/02 12:06:40 wiz Exp $
#

DISTNAME=	koth-0.7.6
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www-unix.oit.umass.edu/~tetron/koth/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www-unix.oit.umass.edu/~tetron/koth/
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
