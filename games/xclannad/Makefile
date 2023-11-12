# $NetBSD: Makefile,v 1.3 2023/11/12 13:21:46 wiz Exp $
#

DISTNAME=	xclannad-7hc
PKGNAME=	xclannad-0.07hc
PKGREVISION=	2
CATEGORIES=	games
#MASTER_SITES=	http://www.creator.club.ne.jp/~jagarl/
MASTER_SITES=	http://teokurebsd.org/netbsd/packages/distfiles/xclannad/

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://web.archive.org/web/20100331135549/http://www.creator.club.ne.jp/~jagarl/xclannad.html
COMMENT=	Interpretor to execute REALLIVE games for Microsoft Windows
LICENSE=	modified-bsd AND gnu-gpl-v2

WRKSRC=		${WRKDIR}/xclannad-0.07h
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++03

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-audiodev=/dev/audio
.endif

SUBST_CLASSES+=		path
SUBST_MESSAGE.path=	Fixing hardcoded paths.
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	configure font/font_peer_ft2.cc
SUBST_SED.path=		-e 's|/usr/local/|${PREFIX}/|g'
SUBST_SED.path+=	-e 's|/usr/pkg/|${PREFIX}/|g'
SUBST_SED.path+=	-e 's|/usr/X11R6/|${X11BASE}/|g'
SUBST_SED.path+=	-e 's|/usr/X11R7/|${X11BASE}/|g'

.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=    gtk2+>=2.6.0
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
