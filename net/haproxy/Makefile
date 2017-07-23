# $NetBSD: Makefile,v 1.35 2017/07/23 17:33:40 adam Exp $

DISTNAME=	haproxy-1.7.8
CATEGORIES=	net www
MASTER_SITES=	http://www.haproxy.org/download/${PKGVERSION_NOREV:R}/src/

MAINTAINER=	morr@NetBSD.org
HOMEPAGE=	http://haproxy.org/
COMMENT=	Reliable, high performance TCP/HTTP load balancer
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
BUILD_MAKE_FLAGS+=	ADDLIB=${COMPILER_RPATH_FLAG}${PREFIX}/lib
BUILD_MAKE_FLAGS+=	TARGET=${TARGET}
BUILD_MAKE_FLAGS+=	USE_REGPARM=1
BUILD_MAKE_FLAGS+=	USE_ZLIB=1

INSTALL_MAKE_FLAGS+=	DOCDIR=${PREFIX}/share/doc/${PKGBASE}
INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
INSTALL_MAKE_FLAGS+=	TARGET=${TARGET}

.include "options.mk"

RCD_SCRIPTS=		haproxy
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS+=	${EGDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
TARGET=netbsd
.elif ${OPSYS} == "FreeBSD"
TARGET=freebsd
.elif ${OPSYS} == "OpenBSD"
TARGET=openbsd
.elif ${OPSYS} == "SunOS"
TARGET=solaris
.elif ${OPSYS} == "Linux"
.  if !empty(OS_VERSION:M2.6.*)
TARGET=linux26
.  elif !empty(OS_VERSION:M2.4.*)
.    if exists(/usr/include/linux/eventpoll.h)
TARGET=linux24e
.    else
TARGET=linux24
.    endif
.  else
TARGET=linux2628
.  endif
.else
TARGET=generic
.endif

LIBS.SunOS+=		-lxnet

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/architecture.txt ${DESTDIR}${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/configuration.txt ${DESTDIR}${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/*.cfg ${DESTDIR}${EGDIR}/

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
