# $NetBSD: Makefile,v 1.20 2009/07/25 10:26:17 obache Exp $
#

DISTNAME=	dnstop-20090128
CATEGORIES=	net
MASTER_SITES=	http://dns.measurement-factory.com/tools/dnstop/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dns.measurement-factory.com/tools/dnstop/
COMMENT=	Diagnose tcpdump trace for DNS queries/replies

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 share/doc/dnstop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnstop ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/dnstop.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/dnstop

.include "../../devel/ncurses/buildlink3.mk"
BUILDLINK_API_DEPENDS.libpcap+=		libpcap>=0.7.0
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
