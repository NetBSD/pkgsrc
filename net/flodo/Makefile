# $NetBSD: Makefile,v 1.12 2008/03/10 10:33:38 wiz Exp $
#

DISTNAME=		flodo-v4
PKGNAME=		flodo-4.20040907
CATEGORIES=		net
MASTER_SITES=		http://arctic.org/~dean/flodo/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://arctic.org/~dean/flodo/
COMMENT=		Simple network flow sampling tool

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.8

CPPFLAGS+=		-I${BUILDLINK_PREFIX.libpcap}/include
LDFLAGS+=		-L${BUILDLINK_PREFIX.libpcap}/lib

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin

CONFLICTS+=		flodo-4-[0-9]*

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} -o flodo flodo.c hash.c local_mac.c -lpcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flodo ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/flodo.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
