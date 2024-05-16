# $NetBSD: Makefile,v 1.55 2024/05/16 06:14:53 wiz Exp $

DISTNAME=	enigma-1.21
PKGNAME=	${DISTNAME:S/-r/./}
PKGREVISION=	15
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=enigma-game/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/enigma/
COMMENT=	Puzzle game similar to Oxyd/Rock'n'Roll/Marble Madness
LICENSE=	gnu-gpl-v2

DEPENDS+=	gettext-tools-[0-9]*:../../devel/gettext-tools
TOOL_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

WRKSRC=			${WRKDIR}/${DISTNAME:S/-r1914//}
USE_LANGUAGES=		c c++11
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

CONFIGURE_ARGS.NetBSD+=	ac_cv_func_gethostbyname_r=no

LDFLAGS.SunOS+=	-lsocket -lnsl

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
.include "../../www/curl/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
