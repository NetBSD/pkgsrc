# $NetBSD: Makefile,v 1.3 2004/05/05 15:57:17 salo Exp $
#

DISTNAME=	libmatroska-0.7.0
CATEGORIES=	multimedia devel
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.matroska.org/
COMMENT=	Extensible open standard Audio/Video container format

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c++

NO_CONFIGURE=	yes
MAKEFLAGS+=	prefix="${PREFIX}"
BUILD_DIRS=	${WRKDIR}/${DISTNAME}/make/linux

.include "../../devel/libebml/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
