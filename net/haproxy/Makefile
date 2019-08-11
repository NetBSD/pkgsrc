# $NetBSD: Makefile,v 1.49 2019/08/11 09:09:41 maya Exp $

DISTNAME=	haproxy-2.0.3
CATEGORIES=	net www
MASTER_SITES=	http://www.haproxy.org/download/${PKGVERSION_NOREV:R}/src/

MAINTAINER=	morr@NetBSD.org
HOMEPAGE=	http://www.haproxy.org/
COMMENT=	Reliable, high performance TCP/HTTP load balancer
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c
USE_TOOLS+=		gmake
BUILD_MAKE_FLAGS+=	ADDLIB=${COMPILER_RPATH_FLAG}${PREFIX}/lib
BUILD_MAKE_FLAGS+=	CC=${CC:Q}
BUILD_MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
BUILD_MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
BUILD_MAKE_FLAGS+=	TARGET=${TARGET}
BUILD_MAKE_FLAGS+=	USE_REGPARM=1
BUILD_MAKE_FLAGS+=	USE_ZLIB=1

INSTALL_MAKE_FLAGS+=	DOCDIR=${PREFIX}/share/doc/${PKGBASE}
INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX}
INSTALL_MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}
INSTALL_MAKE_FLAGS+=	TARGET=${TARGET}
# skip install-doc
INSTALL_TARGET=		install-bin install-man

.include "options.mk"

RCD_SCRIPTS=		haproxy
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
INSTALLATION_DIRS+=	${DOCDIR} ${EGDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD"
TARGET=	${OPSYS:tl}
.elif ${OPSYS} == "Darwin"
TARGET=	osx
.elif ${OPSYS} == "SunOS"
TARGET=	solaris
.elif ${OPSYS} == "Linux"
.  if !empty(OS_VERSION:M2.6.*)
TARGET=	linux26
.  elif !empty(OS_VERSION:M2.4.*)
.    if exists(/usr/include/linux/eventpoll.h)
TARGET=	linux24e
.    else
TARGET=	linux24
.    endif
.  else
TARGET=	linux2628
.  endif
.else
TARGET=	generic
.endif

LIBS.SunOS+=		-lxnet

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/architecture.txt ${DESTDIR}${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/configuration.txt ${DESTDIR}${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/*.cfg ${DESTDIR}${EGDIR}/

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
