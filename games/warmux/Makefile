# $NetBSD: Makefile,v 1.49 2023/01/29 21:16:22 ryoon Exp $

DISTNAME=	warmux-11.04.1
PKGREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://ftp.nluug.nl/ibiblio/distributions/slitaz/sources/packages-cooking/w/ \
	http://mirror.clarkson.edu/slitaz/sources/packages/w/ \
	http://ftp.ec-m.fr/pub/OpenBSD/distfiles/ \
	https://ftp.uni-erlangen.de/gentoo/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.warmux.org/
COMMENT=	Battle game
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++03
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config msgfmt
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-fribidi
CONFIGURE_ARGS+=	--enable-servers
WRKSRC=			${WRKDIR}/warmux-11.04

BUILDLINK_TRANSFORM+=	rm:-Wl,--as-needed

CHECK_PORTABILITY_SKIP+=	build/win32_setup/create_setup.sh.in

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../textproc/libxml++/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
