# $NetBSD: Makefile,v 1.5 2019/07/28 19:50:55 nia Exp $

DISTNAME=	grafX2-v2.6
PKGNAME=	${DISTNAME:S/X2-v/x2-/}
CATEGORIES=	graphics
MASTER_SITES=	https://gitlab.com/GrafX2/grafX2/-/archive/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://grafx2.chez.com/
COMMENT=	Ultimate 256-color bitmap paint program
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	curl gmake pkg-config
USE_LANGUAGES=	c c++

WRKSRC=		${WRKDIR}/${DISTNAME}/src

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
