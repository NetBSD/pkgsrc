# $NetBSD: Makefile,v 1.5 2018/12/09 21:05:34 adam Exp $
#

DISTNAME=		xl2tpd-20171013
CATEGORIES=		net
MASTER_SITES=		-https://github.com/xelerance/xl2tpd/archive/master.zip
EXTRACT_SUFX=		.zip
WRKSRC=			${WRKDIR}/xl2tpd-master

MAINTAINER=		christos@NetBSD.org
HOMEPAGE=		http://www.xelerance.com/services/software/xl2tpd/
COMMENT=		Layer 2 Protocol Daemon

EXDIR=			${PREFIX}/share/examples
INSTALLATION_DIRS+=	${EXDIR}/xl2tpd \
			${EXDIR}/rc.d

post-install:
.for i in chap-secrets ipsec.conf options.xl2tpd psk.txt racoon.conf xl2tpd.conf
	${INSTALL_DATA} ${FILESDIR}/${i} ${DESTDIR}${EXDIR}/xl2tpd/${i}
.endfor
	${INSTALL_SCRIPT} ${FILESDIR}/xl2tpd ${DESTDIR}${EXDIR}/rc.d/xl2tpd

.include "../../mk/compiler.mk"
.include "../../mk/bsd.pkg.mk"
