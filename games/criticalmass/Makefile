# $NetBSD: Makefile,v 1.47 2019/07/01 04:08:10 ryoon Exp $
#

DISTNAME=	CriticalMass-1.0.2
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	16
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=criticalmass/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://criticalmass.sourceforge.net/
COMMENT=	SDL/OpenGL space shoot'em up game

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++03
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

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
