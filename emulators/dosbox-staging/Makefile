# $NetBSD: Makefile,v 1.5 2025/12/14 10:07:19 vins Exp $

DISTNAME=	dosbox-staging-0.82.2
PKGREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=dosbox-staging/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dosbox-staging.org/
COMMENT=	Modern continuation of DOSBox
LICENSE=	gnu-gpl-v2

CONFLICTS=	dosbox-[0-9]*	# bin/dosbox

USE_LANGUAGES=	c c++
USE_TOOLS+=	bash:build pkg-config

USE_CXX_FEATURES=	c++20   # notify_all/wait support in struct std::atomic<>
GCC_REQD+=		11	# which requires gcc-11 at least

LDFLAGS.SunOS+=	-lsocket

.include "options.mk"

SUBST_CLASSES+=		fixme
SUBST_STAGE.fixme=	pre-configure
SUBST_FILES.fixme=	docs/dosbox.1
SUBST_SED.fixme=	-e s,/usr/share/,${PREFIX}/share/,g

.include "../../archivers/zlib-ng/buildlink3.mk"
.include "../../audio/iir1/buildlink3.mk"
.include "../../audio/mt32emu/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../audio/speexdsp/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../net/libslirp/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
