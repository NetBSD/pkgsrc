# $NetBSD: Makefile,v 1.36 2026/09/02 19:00:47 wiz Exp $

DISTNAME=	faudio-22.05
PKGREVISION=	15
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=FNA-XNA/}
GITHUB_PROJECT=	FAudio

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fna-xna.github.io/
COMMENT=	Accuracy-focused XAudio reimplementation for open platforms
LICENSE=	zlib

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DFFMPEG=ON
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/SDL2/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
