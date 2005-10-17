# $NetBSD: Makefile,v 1.1.1.1 2005/10/17 08:08:43 wiz Exp $
#

DISTNAME=		interLOGIC-src-0.30
# authors' preferred casing
PKGNAME=		InterLOGIC-0.30
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=interlogic/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/interlogic/
COMMENT=		Logic/puzzle game based on the old Amiga game "Balls"

WRKSRC=			${WRKDIR}/interlogic
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGBASE}

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
