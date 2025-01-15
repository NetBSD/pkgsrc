# $NetBSD: Makefile,v 1.1 2025/01/15 14:13:39 manu Exp $

DISTNAME=	coturn-4.6.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=coturn/}
GITHUB_PROJECT=	coturn

MAINTAINER=	kethzer.dr@gmail.com
HOMEPAGE=	https://github.com/coturn/coturn
COMMENT=	VoIP media traffic NAT traversal server
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

HAS_CONFIGURE=	yes

# Pass cflags/libs
CONFIGURE_ENV+=		PTHREAD_LIBS=-pthread TURN_DISABLE_RPATH=1
CONFIGURE_ENV+=		LIBEVENT_OPENSSL_CFLAGS="-I${BUILDLINK_PREFIX.libevent}/include"
CONFIGURE_ENV+=		LIBEVENT_OPENSSL_LIBS="-L${BUILDLINK_PREFIX.libevent}/lib -levent_openssl -levent"

# Configure installation paths.
# \todo Why is this not setting PREFIX?
CONFIGURE_ENV+=		BINDIR=${PREFIX}/bin
CONFIGURE_ENV+=		LIBDIR=${PREFIX}/lib
CONFIGURE_ENV+=		MANPREFIX=${PREFIX}
CONFIGURE_ENV+=		CONFDIR=${PKG_SYSCONFDIR}
CONFIGURE_ENV+=		INCLUDEDIR=${PREFIX}/include
CONFIGURE_ENV+=		LOCALSTATEDIR=${PREFIX}/var/turnserver
CONFIGURE_ENV+=		DOCSDIR=${PREFIX}/share/doc/coturn
CONFIGURE_ENV+=		EXAMPLESDIR=${PREFIX}/share/examples/coturn
CONFIGURE_ENV+=		TURNDBDIR=${VARBASE}/turnserver
CONFIGURE_ENV+=		TURNINCLUDEDIR=${PREFIX}/include/turn
CONFIGURE_ENV+=		TURN_NO_MYSQL=1

CFLAGS+=		-Wno-stringop-truncation

COTURN_CONFIG=		${PKG_SYSCONFDIR}/turnserver.conf
COTURN_EGDIR=		${PKG_SYSCONFDIR}
CONF_FILES+=		${COTURN_EGDIR}/turnserver.conf.default ${COTURN_CONFIG}

RCD_SCRIPTS=		turnserver

WRKSRC=		${WRKDIR}/${DISTNAME}

BUILD_DEFS+=	VARBASE

.include "options.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
