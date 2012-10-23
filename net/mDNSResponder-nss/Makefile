# $NetBSD: Makefile,v 1.12 2012/10/23 17:18:36 asau Exp $

DISTNAME=	mDNSResponder-258.14
PKGNAME=	mDNSResponder-nss-258.14
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.opensource.apple.com/tarballs/mDNSResponder/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.apple.com/bonjour/
COMMENT=	Apple's mDNS responder - NetBSD nsswitch module
LICENSE=	modified-bsd

# needs nsswitch
ONLY_FOR_PLATFORM=	NetBSD-[3-9]*-*

INSTALLATION_DIRS=	lib share/examples/nss_mdns ${PKGMANDIR}/man5

BUILD_DEFS+=		PKG_SYSCONFBASE
CONF_FILES=		${PREFIX}/share/examples/nss_mdns/nss_mdns.conf \
			${PKG_SYSCONFDIR}/nss_mdns.conf

post-extract:
	${CP} ${FILESDIR}/netbsd.c ${FILESDIR}/netbsd.h ${WRKSRC}/mDNSPosix

do-build:
	(cd ${WRKSRC}/mDNSPosix && ${CC} -c -fPIC -I. -I${LOCALBASE}/include \
		-DPKG_SYSCONFBASE=\"${PKG_SYSCONFBASE}\" nss_mdns.c netbsd.c)
	(cd ${WRKSRC}/mDNSPosix && ${LD} -shared *.o -o nss_mdns.so.0 \
		-L${LOCALBASE}/lib -Wl,-R${LOCALBASE}/lib -ldns_sd)

do-install:
	${INSTALL_LIB} ${WRKSRC}/mDNSPosix/nss_mdns.so.0 ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/mDNSPosix/nss_mdns.conf \
		${DESTDIR}${PREFIX}/share/examples/nss_mdns
	${INSTALL_MAN} ${WRKSRC}/mDNSPosix/nss_mdns.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
