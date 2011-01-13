# $NetBSD: Makefile,v 1.9 2011/01/13 13:37:51 wiz Exp $
#

DISTNAME=		spaceracer-0.2.4
PKGREVISION=		4
CATEGORIES=		games
MASTER_SITES=		http://spaceracer.sourceforge.net/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://spaceracer.sourceforge.net/
COMMENT=		3D car racing game

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		automake autoconf

pre-configure:
	cd ${WRKSRC:Q} && autoreconf -i

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
