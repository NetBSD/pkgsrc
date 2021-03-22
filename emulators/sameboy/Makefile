# $NetBSD: Makefile,v 1.7 2021/03/22 14:36:09 nia Exp $

.include "Makefile.common"

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://sameboy.github.io/
COMMENT=	Highly accurate Game Boy and Game Boy Color emulator

BUILD_TARGET=	sdl

MAKE_FLAGS+=	DATA_DIR=${PREFIX}/share/sameboy/
MAKE_FLAGS+=	FREEDESKTOP=true

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
