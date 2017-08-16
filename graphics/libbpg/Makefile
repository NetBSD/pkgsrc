# $NetBSD: Makefile,v 1.2 2017/08/16 20:21:09 wiz Exp $

DISTNAME=	libbpg-0.9.2
CATEGORIES=	graphics
MASTER_SITES=	https://bellard.org/bpg/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	https://bellard.org/bpg/
COMMENT=	Better Portable Graphics image format library
LICENSE=	modified-bsd

USE_TOOLS+=	gmake
USE_LANGUAGES+=	c c++

AUTO_MKDIRS=	yes

SUBST_CLASSES+= config
SUBST_MESSAGE.config= config.h file substitutions
SUBST_STAGE.config= pre-configure
SUBST_FILES.config= config.h
SUBST_SED.config=	-e "s,@PREFIX@,${PREFIX},g"

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
