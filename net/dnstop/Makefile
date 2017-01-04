# $NetBSD: Makefile,v 1.26 2017/01/04 10:01:44 roy Exp $
#

DISTNAME=	dnstop-20140915
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://dns.measurement-factory.com/tools/dnstop/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dns.measurement-factory.com/tools/dnstop/
COMMENT=	Diagnose tcpdump trace for DNS queries/replies
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 share/doc/dnstop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dnstop.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/dnstop

BUILDLINK_API_DEPENDS.libpcap+=		libpcap>=0.7.0
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
