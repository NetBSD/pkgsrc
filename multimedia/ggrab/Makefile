# $NetBSD: Makefile,v 1.3 2008/03/04 19:32:30 jlam Exp $
#

DISTNAME=		${PKGNAME}-linux
PKGNAME=		ggrab-0.22a
CATEGORIES=		multimedia
MASTER_SITES=		http://www.menzebach.de/ggrab/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.menzebach.de/ggrab/
COMMENT=		Server for recording video streams from dream dvb-receivers

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c++
WRKSRC=			${WRKDIR}/ggrab-0.22a

RCD_SCRIPTS=		sserver
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ggrab ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sserver ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}/

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
