# $NetBSD: Makefile,v 1.5 2004/04/17 16:42:25 grant Exp $
#

DISTNAME=	libebml-0.6.5
CATEGORIES=	devel
MASTER_SITES=	http://dl.matroska.org/downloads/libebml/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.sourceforge.net/projects/ebml/
COMMENT=	Extensible Binary Meta Language support library

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c++

NO_CONFIGURE=	yes
MAKEFLAGS+=	prefix="${PREFIX}"
BUILD_DIRS=	${WRKDIR}/${DISTNAME}/make/linux

.include "../../mk/bsd.pkg.mk"
