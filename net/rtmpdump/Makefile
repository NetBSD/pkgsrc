# $NetBSD: Makefile,v 1.30 2026/01/07 08:48:27 wiz Exp $

DISTNAME=	rtmpdump-2.6-git-6f6bb1353fc84f4cc37138baa99f586750028a01
PKGNAME=	${DISTNAME:S/-git-/.0.0./}
PKGREVISION=	1
CATEGORIES=	net multimedia
#MASTER_SITES=	# manually created tarball from https://git.ffmpeg.org/rtmpdump

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://rtmpdump.mplayerhq.hu/
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

.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
