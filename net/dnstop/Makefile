# $NetBSD: Makefile,v 1.15 2006/10/04 21:53:16 wiz Exp $
#

DISTNAME=	dnstop-20050203
CATEGORIES=	net
MASTER_SITES=	http://dns.measurement-factory.com/tools/dnstop/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dns.measurement-factory.com/tools/dnstop/
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
