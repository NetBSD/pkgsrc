# $NetBSD: Makefile,v 1.18 2006/10/06 21:01:57 adam Exp $

DISTNAME=	stellarium-0.8.2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=stellarium/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.stellarium.org/
COMMENT=	Generate photorealistic skies with OpenGL

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
