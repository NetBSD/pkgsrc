# $NetBSD: Makefile,v 1.55 2024/01/30 14:21:48 ryoon Exp $

PKGREVISION= 16
.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0ldsk00l.ca/nestopia/
COMMENT=	Portable, very accurate NES emulator

GNU_CONFIGURE=	yes

USE_TOOLS+=	autoreconf autoconf automake
USE_TOOLS+=	pkg-config

TOOL_DEPENDS+=	autoconf-archive-[0-9]*:../../devel/autoconf-archive

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "options.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
