# $NetBSD: Makefile,v 1.23 2021/09/18 07:34:59 nia Exp $

DISTNAME=	wmmixer-1.9
CATEGORIES=	audio
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	pr@alles.prima.de
HOMEPAGE=	https://www.dockapps.net/wmmixer
COMMENT=	Mixer designed for WindowMaker (dockapp)
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++03
USE_TOOLS+=	pkg-config

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} == "none"
PKG_SKIP_REASON+=	"Needs an OSS implementation"
.else
LDFLAGS+=		${LIBOSSAUDIO}
.endif

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
