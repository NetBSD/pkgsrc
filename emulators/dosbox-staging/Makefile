# $NetBSD: Makefile,v 1.2 2025/10/03 07:40:17 wiz Exp $

DISTNAME=	dosbox-staging-0.82.2
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=dosbox-staging/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dosbox-staging.org/
COMMENT=	Modern continuation of DOSBox
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash pkg-config

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/iir1/buildlink3.mk"
.include "../../audio/mt32emu/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../net/libslirp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
