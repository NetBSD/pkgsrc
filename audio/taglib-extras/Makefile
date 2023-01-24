# $NetBSD: Makefile,v 1.7 2023/01/24 18:36:20 wiz Exp $

DISTNAME=	taglib-extras-1.0.1
PKGREVISION=	1
CATEGORIES=	audio
#MASTER_SITES=	http://www.kollide.net/~jefferai/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.kollide.net/~jefferai/
COMMENT=	Extra plugins for taglib
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE=		taglib-extras.pc.cmake
REPLACE_SH=			taglib-extras-config.cmake

SUBST_CLASSES+=		rpath
SUBST_FILES.rpath=	taglib-extras-config.cmake
SUBST_SED.rpath=	-e "s|-L\\([^ 	]*\\)|${COMPILER_RPATH_FLAG}\\1 -L\\1|g"
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Add rpath to config script.

.include "../../devel/cmake/build.mk"
BUILDLINK_ABI_DEPENDS.taglib+=	taglib>=1.6
.include "../../audio/taglib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
