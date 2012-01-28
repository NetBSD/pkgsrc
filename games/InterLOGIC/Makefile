# $NetBSD: Makefile,v 1.13 2012/01/28 11:00:54 wiz Exp $
#

DISTNAME=		interLOGIC-src-0.30
# authors' preferred casing
PKGNAME=		InterLOGIC-0.30
PKGREVISION=		9
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=interlogic/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/interlogic/
COMMENT=		Logic/puzzle game based on the old Amiga game "Balls"

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/interlogic
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

INSTALLATION_DIRS=	share/doc/InterLOGIC

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/InterLOGIC

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
