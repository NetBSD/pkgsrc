# $NetBSD: Makefile,v 1.7 2016/01/19 04:03:21 dbj Exp $
#

DISTNAME=	freedv-1.1
CATEGORIES=	ham
MASTER_SITES=	http://files.freedv.org/freedv/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	dbj@NetBSD.org
HOMEPAGE=	http://freedv.org/
COMMENT=	FreeDV: HF Digital Voice for Radio Amateurs

LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

USE_CMAKE=	yes
CONFIGURE_DIRS=	build
CMAKE_ARG_PATH=	..
CMAKE_ARGS+=	-DUSE_STATIC_CODEC2=FALSE
CMAKE_ARGS+=	-DUSE_STATIC_SPEEXDSP=FALSE

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	icons
.if ${OPSYS} != "Darwin"
PLIST.icons=	yes
.endif
pre-configure:
	${MKDIR} ${WRKSRC}/build

.include "../../ham/codec2/buildlink3.mk"
.include "../../ham/hamlib/buildlink3.mk"
.include "../../audio/sox/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../audio/portaudio-devel/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
