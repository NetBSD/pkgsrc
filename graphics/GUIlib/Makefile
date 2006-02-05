# $NetBSD: Makefile,v 1.12 2006/02/05 23:09:27 joerg Exp $
#

DISTNAME=	GUIlib-1.1.0
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/GUIlib/src/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/GUIlib/
COMMENT=	Very simple GUI framework library

GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
