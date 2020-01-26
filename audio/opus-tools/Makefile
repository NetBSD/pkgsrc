# $NetBSD: Makefile,v 1.8 2020/01/26 17:30:44 rillig Exp $

DISTNAME=	opus-tools-0.1.9
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/opus/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://opus-codec.org/
COMMENT=	Opus encode, inspect, and decode command-line tools
LICENSE=	2-clause-bsd AND gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf pkg-config

LDFLAGS.SunOS+=	-lsocket -lnsl

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
