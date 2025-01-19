# $NetBSD: Makefile,v 1.54 2025/01/19 21:32:46 fox Exp $

DISTNAME=	din-59
CATEGORIES=	audio
MASTER_SITES=	https://dinisnoise.org/files/

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://dinisnoise.org/
COMMENT=	Open source cross-platform sound synthesizer
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	autoreconf pkg-config gmake
GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

# Work around syntax errors from clang 15.0.0
.if ${OPSYS} == "Darwin" && ${OS_VERSION:R} >= 14
CXXFLAGS+=	-std=c++20
.endif

# Don't depend on -lGL on Darwin, otherwise a black screen is produced
.if ${OPSYS} == "Darwin"
LIBS+=	-ltcl -lSDLmain -lSDL -framework Cocoa -framework OpenGL -lpthread
.else
LIBS+=	-ltcl -lSDL -lGL -lpthread
.endif

.include "options.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
