# $NetBSD: Makefile,v 1.6 2003/01/04 12:25:13 wiz Exp $
#

DISTNAME=	koth-0.7.6
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www-unix.oit.umass.edu/~tetron/koth/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www-unix.oit.umass.edu/~tetron/koth/
COMMENT=	The classic "shoot the other tank" artillery game, networked

GNU_CONFIGURE=	YES
CPPFLAGS+=	-DPKG_SYSCONFDIR=\"\\\"${PKG_SYSCONFDIR:Q}\\\"\"
USE_BUILDLINK2=	YES

EGDIR=		${PREFIX}/share/examples/koth
CONF_FILES=	${EGDIR}/koth.cfg ${PKG_SYSCONFDIR}/koth.cfg

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/koth
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/koth
	${INSTALL_DATA} ${WRKSRC}/src/koth.cfg ${EGDIR}

.include "../../graphics/libggi/buildlink2.mk"
.include "../../graphics/libgii/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
