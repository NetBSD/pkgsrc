# $NetBSD: Makefile,v 1.13 2023/11/12 13:22:01 wiz Exp $

DISTNAME=	grafx2-2.8.3132-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	https://gitlab.com/GrafX2/grafX2/-/jobs/2792657789/artifacts/raw/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://grafx2.gitlab.io/grafX2/
COMMENT=	Ultimate 256-color bitmap paint program
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	curl gmake pkg-config
USE_LANGUAGES=	c c++

WRKSRC=		${WRKDIR}/grafx2/src

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Set PREFIX
SUBST_FILES.fix-paths=		main.c
SUBST_VARS.fix-paths=		PREFIX

BUILD_MAKE_FLAGS+=	LFLAGS=${COMPILER_RPATH_FLAG}${X11BASE}/lib

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
