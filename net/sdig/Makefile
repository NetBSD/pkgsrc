# $NetBSD: Makefile,v 1.15 2008/06/23 03:53:57 dholland Exp $

DISTNAME=	sdig-0.30
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.exploits.org/sdig/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} mactable.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.exploits.org/sdig/
COMMENT=	Switch Digger finds port assignment for hosts on a switched Ethernet

SUBST_CLASSES+=		sdig
SUBST_STAGE.sdig=	post-build
SUBST_MESSAGE.sdig=	Inserting the correct prefix directory.
SUBST_FILES.sdig=	sdig.conf
SUBST_SED.sdig=		-e 's,\$${PREFIX},${PREFIX},g'

INSTALLATION_DIRS+=	${PKGMANDIR}/man8 ${PKGMANDIR}/man5 share/doc \
			share/examples share/misc

post-install:
	${INSTALL_DATA} ${WRKSRC}/sdig.conf ${PREFIX}/share/examples/
	${INSTALL_DATA} ${WRKDIR}/mactable ${PREFIX}/share/misc/
	${INSTALL_DATA} ${WRKSRC}/sdig.8 ${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA} ${WRKSRC}/sdig.conf.5 ${PREFIX}/${PKGMANDIR}/man5/

.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
