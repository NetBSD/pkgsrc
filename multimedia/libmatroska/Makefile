# $NetBSD: Makefile,v 1.1.1.1 2004/04/07 12:52:16 salo Exp $
#

DISTNAME=	libmatroska-0.6.3
CATEGORIES=	multimedia devel
MASTER_SITES=	http://dl.matroska.org/downloads/libmatroska/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.matroska.org/
COMMENT=	Extensible open standard Audio/Video container format

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

NO_CONFIGURE=	yes
MAKEFLAGS+=	prefix="${PREFIX}"
BUILD_DIRS=	${WRKDIR}/${DISTNAME}/make/linux

.include "../../devel/libebml/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
