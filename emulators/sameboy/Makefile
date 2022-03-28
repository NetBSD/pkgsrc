# $NetBSD: Makefile,v 1.12 2022/03/28 10:53:05 tnn Exp $

PKGREVISION= 2
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

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
