# $NetBSD: Makefile,v 1.5 2003/07/21 16:51:34 martti Exp $
#

DISTNAME=	GUIlib-1.1.0
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/GUIlib/src/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/GUIlib/
COMMENT=	Very simple GUI framework library

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
