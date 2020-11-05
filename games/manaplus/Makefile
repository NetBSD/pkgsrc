# $NetBSD: Makefile,v 1.12 2020/11/05 09:08:13 ryoon Exp $

DISTNAME=	manaplus-1.9.3.23
PKGREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://download.evolonline.org/manaplus/download/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://manaplus.org/
COMMENT=	2D MMORPG client for The Mana World, Evol Online, and similar servers
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_LANGUAGES=	c c++

LDFLAGS.SunOS+=	${BUILDLINK_LDADD.gettext}

SUBST_CLASSES+=		eq
SUBST_STAGE.eq=		pre-configure
SUBST_MESSAGE.eq=	Fixing non-portable test operator usage
SUBST_FILES.eq+=	configure
SUBST_SED.eq+=		-e 's|" == "|" = "|g'
SUBST_SED.eq+=		-e 's|" == true|" = true|g'

CONFIGURE_ARGS+=	--with-sdl2

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/SDL2_net/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
