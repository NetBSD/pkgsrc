# $NetBSD: Makefile,v 1.1 2013/07/02 00:22:16 christos Exp $
#

DISTNAME=		xl2tpd-20130626
CATEGORIES=		net
MASTER_SITES=		-https://github.com/xelerance/xl2tpd/archive/master.zip
EXTRACT_SUFX=		.zip
WRKSRC=			${WRKDIR}/xl2tpd-master

MAINTAINER=		christos@NetBSD.org
HOMEPAGE=		http://www.xelerance.com/services/software/xl2tpd/
COMMENT=		Layer 2 Protocol Daemon

EXDIR=			${PREFIX}/share/examples/xl2tpd
INSTALLATION_DIRS=	${EXDIR}

post-install:
.for i in chap-secrets ipsec.conf options.xl2tpd psk.txt racoon.conf xl2tpd xl2tpd.conf
	${INSTALL_DATA} ${FILESDIR}/$i ${DESTDIR}${EXDIR}/$i
.endfor

.include "../../mk/compiler.mk"
.include "../../mk/bsd.pkg.mk"
