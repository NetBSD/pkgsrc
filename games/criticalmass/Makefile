# $NetBSD: Makefile,v 1.77 2026/05/14 16:40:56 ryoon Exp $
#

DISTNAME=	CriticalMass-1.0.2
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	42
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=criticalmass/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://criticalmass.sourceforge.net/
COMMENT=	SDL/OpenGL space shoot'em up game

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

LDFLAGS.SunOS+=	-lsocket -lnsl

# delete builtin curl
post-extract:
	${RM} -rf ${WRKSRC}/curl

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
