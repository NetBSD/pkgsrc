# $NetBSD: Makefile,v 1.8 2003/07/17 22:51:20 grant Exp $
# $FreeBSD: ports/net/libnids/Makefile,v 1.5 2000/04/24 07:42:58 kris Exp $
#

DISTNAME=	libnids-1.14
CATEGORIES=	net security
MASTER_SITES=	http://www.packetfactory.net/Projects/Libnids/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.packetfactory.net/Projects/Libnids/
COMMENT=	Network monitoring library with TCP/IP reassembly

DEPENDS=	libnet-[0-9]*:../../devel/libnet

GNU_CONFIGURE=	yes

do-install:
		${INSTALL_DATA} ${WRKSRC}/src/nids.h ${PREFIX}/include
		${INSTALL_DATA} ${WRKSRC}/src/libnids.a ${PREFIX}/lib
		${INSTALL_DATA} ${WRKSRC}/src/libnids.3 ${PREFIX}/man/man3

.include "../../mk/bsd.pkg.mk"
