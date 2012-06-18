# $NetBSD: Makefile,v 1.15 2012/06/18 03:59:09 dholland Exp $
#

DISTNAME=		exult-1.2
PKGREVISION=		7
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=exult/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://exult.sourceforge.net/
COMMENT=		Open-source Ultima 7 engine

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		yacc
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
