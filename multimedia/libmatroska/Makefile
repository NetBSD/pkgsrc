# $NetBSD: Makefile,v 1.5 2004/05/31 09:50:35 salo Exp $
#

DISTNAME=	libmatroska-0.7.0
CATEGORIES=	multimedia devel
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.matroska.org/
COMMENT=	Extensible open standard Audio/Video container format

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c++

NO_CONFIGURE=	yes
MAKEFLAGS+=	prefix=${PREFIX:Q}
MAKE_ENV+=	CXXFLAGS=${CXXFLAGS:Q} RANLIB=${RANLIB:Q}
BUILD_DIRS=	${WRKDIR}/${DISTNAME}/make/linux

ONLY_FOR_COMPILER=	gcc

.include "../../devel/libebml/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
