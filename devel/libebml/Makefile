# $NetBSD: Makefile,v 1.8 2004/05/31 16:47:48 minskim Exp $
#

DISTNAME=	libebml-0.7.0
CATEGORIES=	devel
MASTER_SITES=	http://dl.matroska.org/downloads/libebml/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.sourceforge.net/projects/ebml/
COMMENT=	Extensible Binary Meta Language support library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c++

NO_CONFIGURE=	yes
MAKEFLAGS+=	prefix="${PREFIX}"
BUILD_DIRS=	${WRKDIR}/${DISTNAME}/make/linux

ONLY_FOR_COMPILER=	gcc

.include "../../mk/bsd.pkg.mk"
