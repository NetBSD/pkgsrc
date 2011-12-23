# $NetBSD: Makefile,v 1.2 2011/12/23 13:36:45 drochner Exp $
#

DISTNAME=	supertuxkart-0.6.2a-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=supertuxkart/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://supertuxkart.sourceforge.net/
COMMENT=	Free 3D kart racing game
#LICENSE=	gnu-gpl-v3 AND Creative-Commons-Attribution AND Creative-Commons-BY-SA AND Creative-Commons-Sampling+ AND FreeArt License AND SoundSnap license AND Public Domain AND Image*After terms

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

.include "../../audio/openal/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../games/plib/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
