# $NetBSD: Makefile,v 1.7 2015/04/25 14:23:04 tnn Exp $

DISTNAME=	tyrquake-0.61_20140630
PKGREVISION=	1
CATEGORIES=	games x11
#MASTER_SITES=	http://disenchant.net/files/engine/
MASTER_SITES=	http://ftp.NetBSD.org/pub/NetBSD/misc/snj/tyrquake/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://disenchant.net/tyrquake/
COMMENT=	Conservative branch of Quake

LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/tyrquake

LDFLAGS+=	${LIBOSSAUDIO}

SUBST_CLASSES+=		audio
SUBST_STAGE.audio=	post-patch
SUBST_MESSAGE.audio=	Fixing path to the audio device.
SUBST_FILES.audio=	common/snd_oss.c
SUBST_SED.audio=	-e "s|/dev/dsp|${DEVOSSAUDIO}|"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tyr-* ${DESTDIR}${PREFIX}/bin

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/xf86dgaproto/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
