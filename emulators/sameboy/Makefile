# $NetBSD: Makefile,v 1.25 2025/02/12 06:44:46 ryoon Exp $

PKGREVISION= 4
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sameboy.github.io/
COMMENT=	Highly accurate Game Boy and Game Boy Color emulator

BUILD_TARGET=	sdl

MAKE_FLAGS+=	DATA_DIR=${PREFIX}/share/sameboy/
MAKE_FLAGS+=	FREEDESKTOP=true

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.endif

.include "options.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
