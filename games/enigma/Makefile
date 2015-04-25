# $NetBSD: Makefile,v 1.35 2015/04/25 14:22:54 tnn Exp $

DISTNAME=	enigma-1.01-r1914
PKGNAME=	${DISTNAME:S/-r/./}
PKGREVISION=	7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=enigma-game/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/enigma/
COMMENT=	Puzzle game similar to Oxyd/Rock'n'Roll/Marble Madness
LICENSE=	gnu-gpl-v2

DEPENDS+=		gettext-tools-[0-9]*:../../devel/gettext-tools

WRKSRC=			${WRKDIR}/${DISTNAME:S/-r1914//}
GCC_REQD+=		3.3
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

BUILDLINK_API_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.6
BUILDLINK_API_DEPENDS.SDL+=		SDL>=1.2.9
BUILDLINK_API_DEPENDS.SDL_ttf+=		SDL_ttf>=2.0.7
BUILDLINK_API_DEPENDS.SDL_image+=	SDL_image>=1.2.4
BUILDLINK_API_DEPENDS.zlib+=		zlib>=1.2.3
BUILDLINK_API_DEPENDS.png+=		png>=1.2.7
BUILDLINK_API_DEPENDS.xerces-c+=	xerces-c>=2.7.0

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
