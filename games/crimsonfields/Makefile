# $NetBSD: Makefile,v 1.12 2004/01/24 13:30:55 grant Exp $
#

DISTNAME=		crimson-0.3.7
PKGNAME=		${DISTNAME:S/crimson/crimsonfields/}
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		http://crimson.seul.org/files/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://crimson.seul.org/
COMMENT=		Tactical war game in the tradition of Battle Isle

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-bi2cf --enable-cfed --enable-comet

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
