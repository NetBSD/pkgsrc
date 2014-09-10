# $NetBSD: Makefile,v 1.4 2014/09/10 15:59:34 jperkin Exp $
#

DISTNAME=	libfishsound-1.0.0
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/libfishsound/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://www.xiph.org/fishsound/
COMMENT=	Provides a simple API for decoding and encoding audio data
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	fishsound.pc.in

.include "options.mk"

.if ${OPSYS} == "SunOS"
BUILDLINK_TRANSFORM+=	rm:-Wl,--version-script=Version_script
.endif

.include "../../multimedia/liboggz/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
