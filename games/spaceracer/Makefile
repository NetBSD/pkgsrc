# $NetBSD: Makefile,v 1.16 2020/03/20 11:57:44 nia Exp $
#

DISTNAME=		spaceracer-0.2.4
PKGREVISION=		7
CATEGORIES=		games
MASTER_SITES=		http://spaceracer.sourceforge.net/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://spaceracer.sourceforge.net/
COMMENT=		3D car racing game

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		automake autoconf

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
