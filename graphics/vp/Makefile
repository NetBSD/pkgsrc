# $NetBSD: Makefile,v 1.13 2009/08/26 19:57:52 sno Exp $
#

DISTNAME=		vp-1.5
PKGREVISION=		8
CATEGORIES=		graphics
MASTER_SITES=		http://math.smsu.edu/~erik/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://math.smsu.edu/~erik/software.php?id=63
COMMENT=		Image viewer

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
