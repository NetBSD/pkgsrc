# $NetBSD: Makefile,v 1.15 2006/05/15 22:49:53 joerg Exp $
#

DISTNAME=		stellarium-0.8.0
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=stellarium/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.stellarium.org/
COMMENT=		Generate photorealistic skies with OpenGL

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
