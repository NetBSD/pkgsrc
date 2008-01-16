# $NetBSD: Makefile,v 1.77 2008/01/16 11:11:23 drochner Exp $
#

DISTNAME=		vice-1.22
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.zimmers.net/pub/cbm/crossplatform/emulators/VICE/ \
			http://www.zimmers.net/anonftp/pub/cbm/crossplatform/emulators/VICE/

MAINTAINER=		kristerw@NetBSD.org
HOMEPAGE=		http://www.viceteam.org/
COMMENT=		Emulator for C64, C128, CBM-II, PET, and VIC20

RESTRICTED=		ROM image copyright is questionable.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		bdftopcf gmake mkfontdir msgfmt
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-fullscreen

INFO_FILES=		YES
FONTS_DIRS.x11=		${PREFIX}/share/vice/fonts
REQD_DIRS+=		${PREFIX}/share/vice/fonts
REQD_DIRS+=		${PREFIX}/share/vice

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == NetBSD)
CONFIGURE_ARGS+=	--without-oss
.endif

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
