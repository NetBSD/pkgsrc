# $NetBSD: Makefile,v 1.99 2012/09/22 13:48:16 ryoon Exp $

DISTNAME=		vice-2.3
PKGREVISION=		9
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=vice-emu:Q}/
MASTER_SITES+=		ftp://ftp.zimmers.net/pub/cbm/crossplatform/emulators/VICE/
MASTER_SITES+=		http://www.zimmers.net/anonftp/pub/cbm/crossplatform/emulators/VICE/

MAINTAINER=		rhialto@falu.nl
HOMEPAGE=		http://vice-emu.sourceforge.net/
COMMENT=		Emulator for C64, C128, CBM-II, PET, VIC20, Plus4 and C16
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

RESTRICTED=		ROM image copyright is questionable.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		bdftopcf gmake mkfontdir msgfmt
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES

INFO_FILES=		YES
FONTS_DIRS.x11=		${PREFIX}/share/vice/fonts
REQD_DIRS+=		${PREFIX}/share/vice/fonts
REQD_DIRS+=		${PREFIX}/share/vice

PLIST_SRC+=		PLIST

.include "options.mk"

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == NetBSD)
CONFIGURE_ARGS+=	--without-oss
CPPFLAGS+=		-DHAVE_STDINT_H
.endif

.if (${OPSYS} == DragonFly)
CPPFLAGS+=		-DHAVE_STDINT_H
.endif

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
