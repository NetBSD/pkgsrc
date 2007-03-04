# $NetBSD: Makefile,v 1.18 2007/03/04 06:49:44 dogcow Exp $
#

DISTNAME=	dnstop-20070219
CATEGORIES=	net
MASTER_SITES=	http://dns.measurement-factory.com/tools/dnstop/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dns.measurement-factory.com/tools/dnstop/
COMMENT=	Diagnose tcpdump trace for DNS queries/replies

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dnstop.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/dnstop
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/dnstop

.include "../../devel/ncurses/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
