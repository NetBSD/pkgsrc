# $NetBSD: Makefile,v 1.2 2000/08/11 08:05:59 itojun Exp $
# $FreeBSD: ports/net/libnet/Makefile,v 1.8 2000/06/02 22:51:19 kris Exp $
#

DISTNAME=	libnet-${VERSION}
CATEGORIES=	net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.packetfactory.net/libnet/

GNU_CONFIGURE=	yes

VERSION=	1.0.1b
WRKSRC=         ${WRKDIR}/Libnet-${VERSION}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/libnet.3 ${PREFIX}/man/man3
	@${MKDIR} ${PREFIX}/share/doc/libnet
	@${MKDIR} ${PREFIX}/share/doc/libnet/html
	@${MKDIR} ${PREFIX}/share/doc/libnet/html/examples
.for i in CHANGELOG CHANGELOG-NEWFUNCTIONS COPYING README README.asn.1 README.bpf README.legacy-applications README.libnet-config README.linux README.rawsockets TODO-1.0 TODO-1.1
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${PREFIX}/share/doc/libnet
.endfor
.for i in 1.html 2.html 3.html 4.html 5.html 6.html 7.html contrib.html fig-3a.gif figure-1.gif figure-2.gif figure-3.gif figure-3a.gif lrm.html
	${INSTALL_DATA} ${WRKSRC}/doc/html/${i} ${PREFIX}/share/doc/libnet/html
.endfor
.for i in libnet-example-1.c libnet-example-2.c libnet-example-3.c libnet-example-4.c
	${INSTALL_DATA} ${WRKSRC}/doc/html/examples/${i} ${PREFIX}/share/doc/libnet/html/examples
.endfor

.include "../../mk/bsd.pkg.mk"
