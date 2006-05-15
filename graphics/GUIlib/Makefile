# $NetBSD: Makefile,v 1.13 2006/05/15 21:35:40 joerg Exp $
#

DISTNAME=	GUIlib-1.1.0
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/GUIlib/src/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/GUIlib/
COMMENT=	Very simple GUI framework library

GNU_CONFIGURE=		YES

USE_LANGUAGES=		c c++
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
