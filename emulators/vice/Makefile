# $NetBSD: Makefile,v 1.168 2022/08/11 05:08:21 gutteridge Exp $

DISTNAME=	vice-3.6.1
PKGREVISION=	5
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
USE_TOOLS+=		bash gmake pkg-config perl flex yacc
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-ethernet
CONFIGURE_ARGS+=	--enable-lame
CONFIGURE_ARGS+=	--with-flac
CONFIGURE_ARGS+=	--with-gif
CONFIGURE_ARGS+=	--with-jpeg
CONFIGURE_ARGS+=	--with-mpg123
CONFIGURE_ARGS+=	--with-png
CONFIGURE_ARGS+=	--with-vorbis
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS.NetBSD+=	--with-sun
CONFIGURE_ARGS.NetBSD+=	--without-oss

# Avoid build changes if these programs are installed
CONFIGURE_ENV+=		ac_cv_prog_SVN=no
CONFIGURE_ENV+=		ac_cv_prog_SVNVERSION=no
CONFIGURE_ARGS+=	--disable-pdf-docs
CONFIGURE_ARGS+=	--enable-html-docs

REQD_DIRS+=		${PREFIX}/share/vice

DEPENDS+=		dos2unix-[0-9]*:../../converters/dos2unix
BUILD_DEPENDS+=		xa65-[0-9]*:../../devel/xa65

REPLACE_BASH+=		src/arch/gtk3/data/unix/mkdesktopfile.sh

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	post-configure
SUBST_FILES.prefix+=	doc/vice.texi
SUBST_SED.prefix=	-e 's|/usr/local|${PREFIX}|g'

INSTALLATION_DIRS+=	share/doc/vice/html
INSTALLATION_DIRS+=	share/doc/vice/html/fonts

# Mess created by xdg-utils; clean it up.
# Install html equivalent of vice.pdf.
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/share/applications/mimeinfo.cache
	cd ${DESTDIR}${PREFIX} && ${MV} etc/xdg/menus/applications-merged/vice-org-vice-org.menu share/vice/ || :
	cd ${DESTDIR}${PREFIX} && ${RMDIR} -r etc || :
	cd ${WRKSRC}/doc/html && ${CP} -r fonts vice_*.html *.css COPYING \
		${DESTDIR}${PREFIX}/share/doc/vice/html/

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
