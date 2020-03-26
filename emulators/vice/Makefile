# $NetBSD: Makefile,v 1.147 2020/03/26 12:26:02 nia Exp $

DISTNAME=	vice-3.4
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vice-emu/}

MAINTAINER=	rhialto@NetBSD.org
HOMEPAGE=	http://vice-emu.sourceforge.net/
COMMENT=	Emulator for C64, C128, CBM-II, PET, VIC20, Plus4 and C16
LICENSE=	gnu-gpl-v2

RESTRICTED=		ROM image copyright is questionable.
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++11
USE_TOOLS+=		bash gmake pkg-config perl flex
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-ethernet
CONFIGURE_ARGS.NetBSD+=	--without-oss

# Avoid PLIST mismatch if these programs are installed
CONFIGURE_ENV+=		ac_cv_prog_TEXI2DVI=no
CONFIGURE_ENV+=		ac_cv_prog_PDFTEX=no

INFO_FILES=		yes
REQD_DIRS+=		${PREFIX}/share/vice

BUILD_DEPENDS+=		xa65-[0-9]*:../../devel/xa65

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-configure
SUBST_FILES.prefix=	man/vice.1
SUBST_FILES.prefix+=	doc/html/index.html
SUBST_FILES.prefix+=	doc/html/darwin.html
SUBST_FILES.prefix+=	doc/vice.info-1
SUBST_FILES.prefix+=	doc/vice.txt
SUBST_SED.prefix=	-e 's|/usr/local|${PREFIX}|g'

.include "options.mk"

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
