# $NetBSD: Makefile,v 1.8 2005/12/11 09:40:45 wiz Exp $
#

DISTNAME=		stellarium-0.6.0
PKGREVISION=		3
CATEGORIES=		misc
MASTER_SITES=		http://stellarium.free.fr/download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://stellarium.free.fr/
COMMENT=		Generate photorealistic skys with OpenGL

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
