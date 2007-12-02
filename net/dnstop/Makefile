# $NetBSD: Makefile,v 1.19 2007/12/02 12:59:11 wiz Exp $
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
BUILDLINK_API_DEPENDS.libpcap+=		libpcap>=0.7.0
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
