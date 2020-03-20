# $NetBSD: Makefile,v 1.4 2020/03/20 11:58:11 nia Exp $

DISTNAME=	stund-0.97
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=stun/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmcneill@invisible.ca
HOMEPAGE=	http://stun.sourceforge.net/
COMMENT=	STUN Client and Server
LICENSE=	vovida-license

WRKSRC=		${WRKDIR}/stund
USE_LANGUAGES=	c++03
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin sbin share/doc/stund

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/server ${DESTDIR}${PREFIX}/sbin/stund
	${INSTALL_PROGRAM} ${WRKSRC}/client ${DESTDIR}${PREFIX}/bin/stun_client
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DESTDIR}${PREFIX}/share/doc/stund

.include "../../mk/bsd.pkg.mk"
