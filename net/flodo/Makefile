# $NetBSD: Makefile,v 1.2 2004/09/30 05:09:39 grant Exp $
#

DISTNAME=		flodo-v3
PKGNAME=		flodo-3-20040907
CATEGORIES=		net
MASTER_SITES=		http://arctic.org/~dean/flodo/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://arctic.org/~dean/flodo/
COMMENT=		Simple network flow sampling tool

USE_BUILDLINK3=		yes
USE_BUILTIN.libpcap=	no
BUILDLINK_DEPENDS.libpcap+=	libpcap>=0.8

CPPFLAGS+=		-I${BUILDLINK_PREFIX.libpcap}/include
LDFLAGS+=		-L${BUILDLINK_PREFIX.libpcap}/lib

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${CPPFLAGS} ${LDFLAGS} -o flodo flodo.c -lpcap
	
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/flodo ${PREFIX}/sbin

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
