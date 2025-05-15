# $NetBSD: Makefile,v 1.6 2025/05/15 11:40:32 nia Exp $

DISTNAME=	stund-0.97
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=stun/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmcneill@invisible.ca
HOMEPAGE=	http://stun.sourceforge.net/
COMMENT=	STUN Client and Server
LICENSE=	vovida-license

WRKSRC=		${WRKDIR}/stund
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

# Fails with C++14 default language
FORCE_CXX_STD=		c++03

# Necessary to get ioctl definitions.
CPPFLAGS.SunOS+=	-DBSD_COMP
LDFLAGS.SunOS+=		-lsocket -lnsl

INSTALLATION_DIRS=	bin sbin share/doc/stund

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/server ${DESTDIR}${PREFIX}/sbin/stund
	${INSTALL_PROGRAM} ${WRKSRC}/client ${DESTDIR}${PREFIX}/bin/stun_client
	${INSTALL_DATA} ${WRKSRC}/license.txt ${DESTDIR}${PREFIX}/share/doc/stund

.include "../../mk/bsd.pkg.mk"
