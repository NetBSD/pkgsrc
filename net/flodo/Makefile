# $NetBSD: Makefile,v 1.1.1.1 2004/09/30 00:13:53 mrg Exp $
#

DISTNAME=		flodo-v3
PKGNAME=		flodo-3-20040907
CATEGORIES=		net
MASTER_SITES=		http://arctic.org/~dean/flodo/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://arctic.org/~dean/flodo/
COMMENT=		simple network flow sampling tool

USE_BUILDLINK3=		yes
USE_BUILTIN.libpcap=	no # NetBSD's libpcap is very old.

CPPFLAGS+=		-I${BUILDLINK_PREFIX.libpcap}/include
LDFLAGS+=		-L${BUILDLINK_PREFIX.libpcap}/lib

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} -o flodo flodo.c -lpcap
	
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flodo ${PREFIX}/sbin

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
