# $NetBSD: Makefile,v 1.1.1.1 2002/01/10 14:06:31 bouyer Exp $

DISTNAME=	sdig-0.11
CATEGORIES=	net
MASTER_SITES=	http://www.exploits.org/sdig/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} mactable.gz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.exploits.org/sdig/
COMMENT=	Switch Digger finds port assignment for hosts on a switched Ethernet

DEPENDS=	ucd-snmp>=4.1.2:../../net/ucd-snmp

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

.include "../../mk/bsd.prefs.mk"

post-extract:
	${GZCAT} < ${DISTDIR}/mactable.gz > ${WRKDIR}/mactable

post-build: my-post-build

post-install:
	${INSTALL_DATA} ${WRKDIR}/sdig.conf ${PREFIX}/share/examples/
	${INSTALL_DATA} ${WRKDIR}/mactable ${PREFIX}/share/misc/

.include "../../mk/bsd.pkg.mk"

# Note:  this depends on having a MESSAGE file, which we do.
#
my-post-build:
	${SED} ${MESSAGE_SUBST_SED} < ${WRKSRC}/sdig.conf > ${WRKDIR}/sdig.conf
