# $NetBSD: Makefile,v 1.7 2005/01/08 05:22:36 mjl Exp $

DISTNAME=		daapd-0.2.3d
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.tgz

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://www.deleet.de/projekte/daap/daapd/
COMMENT=		Server for DAA protocol (iTunes)

USE_LANGUAGES=		c c++
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		YES
USE_GNU_TOOLS+=		make
MAKEFILE=		makefile

RCD_SCRIPTS=		daapd
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

# PKG_SYSCONFSUBDIR=	${PKGBASE}

CONF_FILES=    ${EGDIR}/daapd.conf ${PKG_SYSCONFDIR}/daapd.conf

post-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/daapd-example.conf ${EGDIR}/daapd.conf

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../net/howl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
