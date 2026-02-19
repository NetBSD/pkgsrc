# $NetBSD: Makefile,v 1.6 2026/02/19 08:34:48 wiz Exp $

DISTNAME=		xl2tpd-20171013
CATEGORIES=		net
MASTER_SITES=		-https://github.com/xelerance/xl2tpd/archive/master.zip
EXTRACT_SUFX=		.zip
WRKSRC=			${WRKDIR}/xl2tpd-master

MAINTAINER=		christos@NetBSD.org
HOMEPAGE=		https://github.com/xelerance/xl2tpd
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
