# $NetBSD: Makefile,v 1.6 2003/07/26 21:41:16 jmmv Exp $
#

DISTNAME=		crimson-0.3.4
PKGNAME=		${DISTNAME:S/crimson/crimsonfields/}
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		http://www.lanipage.de/jens/crimson/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.lanipage.de/jens/
COMMENT=		Tactical war game in the tradition of Battle Isle

USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-bi2cf --enable-cfed --enable-comet

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
