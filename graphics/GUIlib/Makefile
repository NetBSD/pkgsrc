# $NetBSD: Makefile,v 1.1.1.1 2001/07/27 09:30:22 zuntum Exp $
#

DISTNAME=	GUIlib-1.1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.libsdl.org/projects/GUIlib/src/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://www.libsdl.org/projects/GUIlib/
COMMENT=	very simple GUI framework library

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
