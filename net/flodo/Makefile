# $NetBSD: Makefile,v 1.4 2004/11/08 04:31:16 mrg Exp $
#

DISTNAME=		flodo-v4
PKGNAME=		flodo-4-20040907
CATEGORIES=		net
MASTER_SITES=		http://arctic.org/~dean/flodo/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://arctic.org/~dean/flodo/
COMMENT=		Simple network flow sampling tool

USE_BUILDLINK3=		yes
USE_BUILTIN.libpcap=	no
BUILDLINK_DEPENDS.libpcap+=	libpcap>=0.8

CPPFLAGS+=		-I${BUILDLINK_PREFIX.libpcap}/include
LDFLAGS+=		-L${BUILDLINK_PREFIX.libpcap}/lib

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} -o flodo flodo.c hash.c local_mac.c -lpcap

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flodo ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/flodo.8 ${PREFIX}/man/man8

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
