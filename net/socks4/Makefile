# $NetBSD: Makefile,v 1.1 1998/06/11 16:03:55 agc Exp $
#

DISTNAME=	export.socks.cstc.4.2.2
PKGNAME=	socks4-2.2
CATEGORIES=	net security
MASTER_SITES=	http://www.ibs.net.pl/archive/Firewalls/socks/socks4/

MAINTAINER=	packages@netbsd.org

CONFLICTS=	socks5-1.0.2

NO_CDROM=	"NEC has a funky license for this software"
RESTRICTED=	"no commercial use"

WRKSRC=		${WRKDIR}/socks.cstc.4.2

NO_CONFIGURE=	yes

MAN1=		rfinger.1 rftp.1 rtelnet.1 rwhois.1 socks_clients.1
MAN5=		sockd.conf.5 sockd.route.5 socks.conf.5
MAN8=		sockd.8

post-patch:
	@${SED} -e 's|@PREFIX@|${PREFIX}|g' ${WRKSRC}/include/socks.h \
		> ${WRKSRC}/include/socks.h.new && \
		${MV} ${WRKSRC}/include/socks.h.new ${WRKSRC}/include/socks.h
	@${ECHO} "sockd 0.0.0.0 0.0.0.0" >> ${WRKSRC}/socks.conf

.include "../../mk/bsd.pkg.mk"
