# $NetBSD: Makefile,v 1.3 2012/10/02 23:48:10 asau Exp $
#

DISTNAME=	taglib-extras-1.0.1
CATEGORIES=	audio
MASTER_SITES=	http://www.kollide.net/~jefferai/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kollide.net/~jefferai/
COMMENT=	Extra plugins for taglib
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE=		taglib-extras.pc.cmake
REPLACE_SH=			taglib-extras-config.cmake

SUBST_CLASSES+=		rpath
SUBST_FILES.rpath=	taglib-extras-config.cmake
SUBST_SED.rpath=	-e "s|-L\\([^ 	]*\\)|${COMPILER_RPATH_FLAG}\\1 -L\\1|g"
SUBST_STAGE.rpath=	pre-configure
SUBST_MESSAGE.rpath=	Add rpath to config script.

BUILDLINK_ABI_DEPENDS.taglib+=	taglib>=1.6
.include "../../audio/taglib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
