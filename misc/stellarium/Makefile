# $NetBSD: Makefile,v 1.10 2006/02/15 18:43:45 drochner Exp $
#

DISTNAME=		stellarium-0.7.1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=stellarium/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://stellarium.free.fr/
COMMENT=		Generate photorealistic skys with OpenGL

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
