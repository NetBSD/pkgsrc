# $NetBSD: Makefile,v 1.3 2004/12/28 23:18:18 reed Exp $
#

DISTNAME=		vp-1.5
PKGREVISION=	2
CATEGORIES=		graphics
MASTER_SITES=		http://math.smsu.edu/~erik/files/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://math.smsu.edu/~erik/software.php?id=63
COMMENT=		Image viewer

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
