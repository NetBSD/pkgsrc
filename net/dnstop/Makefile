# $NetBSD: Makefile,v 1.13 2005/06/17 03:50:24 jlam Exp $
#

DISTNAME=	dnstop-20050203
CATEGORIES=	net
MASTER_SITES=	http://dnstop.measurement-factory.com/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://dnstop.measurement-factory.com/src/
COMMENT=	Diagnose tcpdump trace for DNS queries/replies

INSTALLATION_DIRS=	bin man/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dnstop.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dnstop
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/dnstop

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
