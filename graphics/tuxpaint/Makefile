# $NetBSD: Makefile,v 1.6 2002/12/01 13:49:42 salo Exp $
#

DISTNAME=	tuxpaint-2002.10.26
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/tuxpaint/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.newbreedsoftware.com/tuxpaint/
COMMENT=	drawing program for small children

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
MANCOMPRESSED=		YES

.include "../../audio/SDL-mixer/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/SDL_ttf/buildlink2.mk"
.include "../../graphics/SDL-image/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
