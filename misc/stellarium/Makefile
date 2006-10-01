# $NetBSD: Makefile,v 1.17 2006/10/01 10:27:19 adam Exp $

DISTNAME=	stellarium-0.8.1
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
