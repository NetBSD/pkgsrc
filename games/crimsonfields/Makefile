# $NetBSD: Makefile,v 1.16 2004/03/12 22:15:33 wiz Exp $
#

DISTNAME=		crimson-0.4.1
PKGNAME=		${DISTNAME:S/crimson/crimsonfields/}
CATEGORIES=		games
MASTER_SITES=		http://crimson.seul.org/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://crimson.seul.org/
COMMENT=		Tactical war game in the tradition of Battle Isle

DEPENDS+=		xdg-dirs>=1.1:../../misc/xdg-dirs

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-bi2cf --enable-cfed --enable-comet

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
