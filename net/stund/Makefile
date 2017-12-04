# $NetBSD: Makefile,v 1.1 2017/12/04 23:59:20 jmcneill Exp $

DISTNAME=	stund-0.97
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=stun/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmcneill@invisible.ca
HOMEPAGE=	http://stun.sourceforge.net/
COMMENT=	STUN Client and Server
LICENSE=	vovida-license

WRKSRC=		${WRKDIR}/stund
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin sbin share/doc/stund

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/server ${DESTDIR}${PREFIX}/sbin/stund
	${INSTALL_PROGRAM} ${WRKSRC}/client ${DESTDIR}${PREFIX}/bin/stun_client
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DESTDIR}${PREFIX}/share/doc/stund

.include "../../mk/bsd.pkg.mk"
