# $NetBSD: Makefile,v 1.6 2001/11/29 01:12:47 hubertf Exp $

DISTNAME= 	tcp_wrappers_7.6-ipv6.1
PKGNAME=	tcp_wrappers-7.6.1
PKGREVISION= 	1
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.porcupine.org/pub/security/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	ftp://ftp.porcupine.org/pub/security/index.html
COMMENT=	Monitor and filter incoming requests for network services

ONLY_FOR_PLATFORM=	SunOS-*-*	# in NetBSD base system

USE_LIBTOOL=	YES

ALL_TARGET=	sunos5

.if exists(/usr/include/netinet/ip6.h)
MAKE_ENV+=	IPV6=-DHAVE_IPV6
.endif

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcp_wrappers
	cd ${WRKSRC} && \
	${LIBTOOL} ${INSTALL_DATA} libwrap.la ${PREFIX}/lib && \
	${LIBTOOL} ${INSTALL_PROGRAM} tcpdmatch try-from safe_finger tcpdchk \
	  ${PREFIX}/bin && \
	${INSTALL_DATA} tcpd.h ${PREFIX}/include && \
	${LIBTOOL} ${INSTALL_PROGRAM} tcpd ${PREFIX}/libexec && \
	${INSTALL_DATA} *.3 ${PREFIX}/man/man3 && \
	${INSTALL_DATA} *.5 ${PREFIX}/man/man5 && \
	${INSTALL_DATA} *.8 ${PREFIX}/man/man8 && \
	${INSTALL_DATA} README README.NIS README.ipv6 \
	  ${PREFIX}/share/doc/tcp_wrappers

.include "../../mk/bsd.pkg.mk"
