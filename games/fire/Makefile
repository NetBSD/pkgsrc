# $NetBSD: Makefile,v 1.6 2001/10/24 22:10:55 jlam Exp $
#

DISTNAME=	fire-1.0
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/fire/src/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.libsdl.org/projects/fire/index.html
COMMENT=	organic fireworks demo

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
