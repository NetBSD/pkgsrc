# $NetBSD: Makefile,v 1.8 2001/02/17 18:19:54 wiz Exp $

DISTNAME=	vtun-2.4
CATEGORIES=	net
MASTER_SITES=	http://vtun.sourceforge.net/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://vtun.sourceforge.net/
COMMENT=	Virtual Tunnels over TCP/IP networks with traffic shaping, etc.

DEPENDS+=	liblzo-1.*:../../archivers/liblzo

GNU_CONFIGURE=	YES
USE_SSL=	YES
CONFIGURE_ARGS+=--with-ssl-headers=${SSLBASE}/include/openssl \
		--with-ssl-lib=${SSLBASE}/lib \
		--with-lzo-headers=${LOCALBASE}/include \
		--with-lzo-lib=${LOCALBASE}/lib
LIBS+=		${LDFLAGS}
CONFIGURE_ENV+=	LIBS="${LIBS}"

ALL_TARGET=	vtund
PLIST_SUBST+=	PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
