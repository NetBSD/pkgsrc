# $NetBSD: Makefile,v 1.17 2022/09/11 12:51:34 wiz Exp $

PKGREVISION= 1
.include "Makefile.common"

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://sameboy.github.io/
COMMENT=	Highly accurate Game Boy and Game Boy Color emulator

BUILD_TARGET=	sdl

MAKE_FLAGS+=	DATA_DIR=${PREFIX}/share/sameboy/
MAKE_FLAGS+=	FREEDESKTOP=true

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.endif

.include "options.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
