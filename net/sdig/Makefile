# $NetBSD: Makefile,v 1.7 2004/04/25 08:16:59 snj Exp $

DISTNAME=	sdig-0.30
CATEGORIES=	net
MASTER_SITES=	http://www.exploits.org/sdig/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} mactable.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.exploits.org/sdig/
COMMENT=	Switch Digger finds port assignment for hosts on a switched Ethernet

USE_BUILDLINK3=	yes

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

.include "../../mk/bsd.prefs.mk"

post-extract:
	${GZCAT} < ${DISTDIR}/mactable.gz > ${WRKDIR}/mactable

post-build: my-post-build

post-install:
	${INSTALL_DATA} ${WRKDIR}/sdig.conf ${PREFIX}/share/examples/
	${INSTALL_DATA} ${WRKDIR}/mactable ${PREFIX}/share/misc/
	${INSTALL_DATA} ${WRKSRC}/sdig.8 ${PREFIX}/man/man8/
	${INSTALL_DATA} ${WRKSRC}/sdig.conf.5 ${PREFIX}/man/man5/

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# Note:  this depends on having a MESSAGE file, which we do.
#
my-post-build:
	${SED} ${MESSAGE_SUBST_SED} < ${WRKSRC}/sdig.conf > ${WRKDIR}/sdig.conf
