# $NetBSD: Makefile,v 1.1.1.1 2001/01/19 21:18:16 tron Exp $

DISTNAME= 	tcp_wrappers_7.6-ipv6.1
PKGNAME=	tcp_wrappers-7.6.1
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.porcupine.org/pub/security/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	ftp://ftp.porcupine.org/pub/security/index.html

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

ALL_TARGET=	sunos5

.if exists(/usr/include/netinet/ip6.h)
MAKE_ENV+=	IPV6=-DHAVE_IPV6
.endif

do-install:
	${MKDIR} ${PREFIX}/share/doc/tcp_wrappers
	cd ${WRKSRC} && \
	${INSTALL_PROGRAM} tcpdmatch try-from safe_finger tcpdchk \
	  ${PREFIX}/bin && \
	${INSTALL_DATA} libwrap.a ${PREFIX}/lib && \
	${INSTALL_PROGRAM} tcpd ${PREFIX}/libexec && \
	${INSTALL_DATA} *.3 ${PREFIX}/man/man3 && \
	${INSTALL_DATA} *.5 ${PREFIX}/man/man5 && \
	${INSTALL_DATA} *.8 ${PREFIX}/man/man8 && \
	${INSTALL_DATA} README README.NIS README.ipv6 \
	  ${PREFIX}/share/doc/tcp_wrappers

.include "../../mk/bsd.pkg.mk"
