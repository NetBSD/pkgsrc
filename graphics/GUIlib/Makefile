# $NetBSD: Makefile,v 1.7 2004/04/12 02:20:13 snj Exp $
#

DISTNAME=	GUIlib-1.1.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/GUIlib/src/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/GUIlib/
COMMENT=	Very simple GUI framework library

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
