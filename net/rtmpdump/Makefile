# $NetBSD: Makefile,v 1.10 2017/09/20 06:47:56 adam Exp $

DISTNAME=	rtmpdump-2.4
PKGREVISION=	3
CATEGORIES=	net multimedia
MASTER_SITES=	http://rtmpdump.mplayerhq.hu/download/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://rtmpdump.mplayerhq.hu/
COMMENT=	Tools for handling RTMP stream
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
BUILD_DIRS=	. librtmp
MAKE_ENV+=	XCFLAGS=${CFLAGS:Q}
MAKE_ENV+=	XLDFLAGS=${LDFLAGS:Q}

WRKSRC=		${WRKDIR}/rtmpdump
PKGCONFIG_OVERRIDE+=	librtmp/librtmp.pc.in

LDFLAGS.SunOS+=	-lnsl -lsocket

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
