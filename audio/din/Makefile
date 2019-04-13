# $NetBSD: Makefile,v 1.4 2019/04/13 13:56:43 fox Exp $

DISTNAME=	din-41
CATEGORIES=	audio
MASTER_SITES=	https://archive.org/download/dinisnoise_source_code/

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://dinisnoise.org/
COMMENT=	Open source cross-platform sound synthesizer
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++
USE_TOOLS+=	autoreconf pkg-config gmake
GNU_CONFIGURE=	yes

LDFLAGS+=	-ltcl -lSDL -lGL -lpthread

.include "options.mk"

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
