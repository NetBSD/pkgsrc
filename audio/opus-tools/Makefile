# $NetBSD: Makefile,v 1.4 2013/01/20 20:10:51 ryoon Exp $
#

DISTNAME=	opus-tools-0.1.6
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/opus/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://opus-codec.org/
COMMENT=	Opus encode, inspect, and decode command-line tools
LICENSE=	2-clause-bsd AND gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf pkg-config

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../audio/libopus/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
