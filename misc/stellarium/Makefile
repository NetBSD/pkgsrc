# $NetBSD: Makefile,v 1.9 2006/02/05 23:10:14 joerg Exp $
#

DISTNAME=		stellarium-0.6.0
PKGREVISION=		4
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
