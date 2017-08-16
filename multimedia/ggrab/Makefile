# $NetBSD: Makefile,v 1.7 2017/08/16 20:45:41 wiz Exp $
#

DISTNAME=		${PKGNAME}-linux
PKGNAME=		ggrab-0.22a
CATEGORIES=		multimedia
#MASTER_SITES=		http://www.menzebach.de/ggrab/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.menzebach.de/ggrab/
COMMENT=		Server for recording video streams from dream dvb-receivers

USE_LANGUAGES=	c++
WRKSRC=			${WRKDIR}/ggrab-0.22a

RCD_SCRIPTS=		sserver
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	bin ${DOCDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ggrab ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sserver ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}/

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
