# $NetBSD: Makefile,v 1.13 2004/01/05 12:04:20 jlam Exp $

DISTNAME= 	tcp_wrappers_7.6-ipv6.1
PKGNAME=	tcp_wrappers-7.6.1
PKGREVISION= 	1
CATEGORIES=	security net
MASTER_SITES=	ftp://ftp.porcupine.org/pub/security/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	ftp://ftp.porcupine.org/pub/security/index.html
COMMENT=	Monitor and filter incoming requests for network services

ONLY_FOR_PLATFORM=	IRIX-*-* Darwin-*-* SunOS-*-* Linux-*-*	# in NetBSD base system

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
ALL_TARGET=	netbsd
.elif ${OPSYS} == "SunOS"
ALL_TARGET=	sunos5
.elif ${OPSYS} == "IRIX" || ${OPSYS} == "Linux"
ALL_TARGET=	${LOWER_OPSYS}
.else
ALL_TARGET=	generic		# good luck!
.endif

.if defined(USE_INET6) && ${USE_INET6} == "YES" && ${OPSYS} != "Linux"
MAKE_ENV+=	IPV6=-DHAVE_IPV6
.endif

do-install:
	cd ${WRKSRC}; ${PKGLIBTOOL} ${INSTALL_DATA} libwrap.la ${PREFIX}/lib
	cd ${WRKSRC}; ${PKGLIBTOOL} ${INSTALL_PROGRAM} \
		tcpdmatch try-from safe_finger tcpdchk ${PREFIX}/bin
	cd ${WRKSRC}; ${INSTALL_DATA} tcpd.h ${PREFIX}/include
	cd ${WRKSRC}; ${PKGLIBTOOL} ${INSTALL_PROGRAM} tcpd ${PREFIX}/libexec
	cd ${WRKSRC}; ${INSTALL_DATA} *.3 ${PREFIX}/man/man3
	cd ${WRKSRC}; ${INSTALL_DATA} *.5 ${PREFIX}/man/man5
	cd ${WRKSRC}; ${INSTALL_DATA} *.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tcp_wrappers
	cd ${WRKSRC}; ${INSTALL_DATA} README README.NIS README.ipv6 \
		${PREFIX}/share/doc/tcp_wrappers

.include "../../mk/bsd.pkg.mk"
