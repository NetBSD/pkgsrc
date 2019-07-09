# $NetBSD: Makefile,v 1.3 2019/07/09 15:38:23 nia Exp $

DISTNAME=	grafx2-2.5.1960-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	graphics
MASTER_SITES=	-http://pulkomandy.tk/projects/GrafX2/downloads/30
EXTRACT_SUFX=	.tgz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://pulkomandy.tk/projects/GrafX2/
COMMENT=	Ultimate 256-color bitmap paint program
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/grafx2/src
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Set PREFIX
SUBST_FILES.fix-paths=		main.c
SUBST_VARS.fix-paths=		PREFIX

BUILD_MAKE_FLAGS+=	LFLAGS=${COMPILER_RPATH_FLAG}${X11BASE}/lib

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
