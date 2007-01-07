# $NetBSD: Makefile,v 1.4 2007/01/07 09:14:03 rillig Exp $

DISTNAME=	mDNSResponder-108
PKGNAME=	mDNSResponder-nss-108
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://darwinsource.opendarwin.org/tarballs/apsl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.apple.com/darwin/projects/bonjour/
COMMENT=	Apple's mDNS responder - NetBSD nsswitch module

# needs nsswitch
ONLY_FOR_PLATFORM=	NetBSD-[3-9]*-*

post-extract:
	${CP} ${FILESDIR}/netbsd.c ${FILESDIR}/netbsd.h ${WRKSRC}/mDNSPosix

do-build:
	(cd ${WRKSRC}/mDNSPosix && ${CC} -c -fPIC -I. -I${LOCALBASE}/include \
		nss_mdns.c netbsd.c)
	(cd ${WRKSRC}/mDNSPosix && ${LD} -shared *.o -o nss_mdns.so.0 \
		-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -ldns_sd)

do-install:
	${INSTALL_DATA} ${WRKSRC}/mDNSPosix/nss_mdns.so.0 ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/nss_mdns
	${INSTALL_DATA} ${WRKSRC}/mDNSPosix/nss_mdns.conf \
		${PREFIX}/share/examples/nss_mdns
	${INSTALL_MAN} ${WRKSRC}/mDNSPosix/nss_mdns.conf.5 ${PREFIX}/${PKGMANDIR}/man5

.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
