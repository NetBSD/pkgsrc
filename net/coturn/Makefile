# $NetBSD: Makefile,v 1.3 2025/01/23 17:06:18 gdt Exp $

DISTNAME=	coturn-4.6.3
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=coturn/}

MAINTAINER=	kethzer.dr@gmail.com
#MAINTAINER+=	gdt@NetBSD.org
HOMEPAGE=	https://github.com/coturn/coturn
COMMENT=	TURN and STUN server (for VoIP/webrtc)
LICENSE=	modified-bsd

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-rpath
CONFIGURE_ARGS+=	--localstatedir ${VARBASE}/turnserver
CONFIGURE_ARGS+=	--prefix ${PREFIX}

# Pass cflags/libs
CONFIGURE_ENV+=		LIBEVENT_OPENSSL_CFLAGS="-I${BUILDLINK_PREFIX.libevent}/include"
CONFIGURE_ENV+=		LIBEVENT_OPENSSL_LIBS="-L${BUILDLINK_PREFIX.libevent}/lib -levent_openssl -levent"

# \todo File a bug upstream, or explain why the warning is wrong.
CFLAGS+=	-Wno-stringop-truncation

COTURN_CONFIG=	${PKG_SYSCONFDIR}/turnserver.conf
COTURN_EGDIR=	${PREFIX}/share/examples/turnserver
CONF_FILES=	${COTURN_EGDIR}/turnserver.conf.default ${COTURN_CONFIG}

BUILD_DEFS+=	VARBASE
RCD_SCRIPTS=	turnserver

.include "options.mk"

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/turnserver.conf.default \
		${DESTDIR}${COTURN_EGDIR}/turnserver.conf.default

.include "../../devel/libevent/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
