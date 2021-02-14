# $NetBSD: Makefile,v 1.1 2021/02/14 11:32:47 leot Exp $

DISTNAME=	farbfeld-4
CATEGORIES=	graphics
MASTER_SITES=	http://dl.suckless.org/farbfeld/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	http://tools.suckless.org/farbfeld/
COMMENT=	Suckless image format with conversion tools
LICENSE=	isc

# Needed for `convert' by 2ff
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

SUBST_CLASSES+=		configmk
SUBST_STAGE.configmk=	pre-configure
SUBST_MESSAGE.configmk=	Adjusting config.mk
SUBST_FILES.configmk=	config.mk
SUBST_SED.configmk+=	-e '/^CPPFLAGS/s/=/+=/'
SUBST_SED.configmk+=	-e '/^CFLAGS/s/=/+=/'
SUBST_SED.configmk+=	-e '/^LDFLAGS/s/=/+=/'
SUBST_SED.configmk+=	-e '/^CFLAGS/s/-Os//'
SUBST_SED.configmk+=	-e '/^LDFLAGS/s/-s//'
SUBST_SED.configmk+=	-e 's/cc/'${CC:Q}'/'

USE_LANGUAGES=	c99

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
