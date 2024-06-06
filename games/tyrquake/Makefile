# $NetBSD: Makefile,v 1.12 2024/06/06 17:33:14 ktnb Exp $

DISTNAME=	tyrquake-0.71
CATEGORIES=	games x11
MASTER_SITES=	https://disenchant.net/files/engine/

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	https://disenchant.net/tyrquake/
COMMENT=	Conservative branch of Quake
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

LDFLAGS+=	${LIBOSSAUDIO}

SUBST_CLASSES+=		audio
SUBST_STAGE.audio=	pre-configure
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
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
