# $NetBSD: Makefile,v 1.15 2004/03/08 19:40:38 jmmv Exp $
#

DISTNAME=		crimson-0.3.8
PKGNAME=		${DISTNAME:S/crimson/crimsonfields/}
PKGREVISION=		1
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
.include "../../mk/bsd.pkg.mk"
