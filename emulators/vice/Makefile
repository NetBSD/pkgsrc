# $NetBSD: Makefile,v 1.43 2004/05/25 21:51:42 wiz Exp $
#

DISTNAME=		vice-1.14
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.funet.fi/pub/cbm/crossplatform/emulators/VICE/ \
			http://www.nic.funet.fi/pub/cbm/crossplatform/emulators/VICE/

MAINTAINER=		kristerw@NetBSD.org
HOMEPAGE=		http://www.viceteam.org/
COMMENT=		Emulator for C64, C128, CBM-II, PET, and VIC20

BUILD_USES_MSGFMT=	YES

RESTRICTED=		"ROM image copyright is questionable"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
USE_GCC_SHLIB=		YES

INFO_FILES=		vice.info

.include "../../mk/bsd.prefs.mk"

.if !empty(VICE_USE_FFMPEG:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ffmpeg
.endif

# These changes are rather common, so sed instead of patch:
post-patch:
	@for file in `${FIND} ${WRKSRC} -name Makefile.in -print`	\
			${WRKSRC}/src/arch/unix/archdep.h; do		\
		${MV} -f $$file $$file.orig &&				\
		${SED}  -e "s|/lib/vice/doc|/share/doc/vice|g"		\
			-e "s|/lib/vice|/share/vice|g"			\
			-e "/^pkglibdir/s|(libdir)|(datadir)|g"		\
			$$file.orig >$$file;				\
	done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/vice
	${MV} ${PREFIX}/share/doc/vice/*.html ${PREFIX}/share/doc/html/vice

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.if !empty(VICE_USE_FFMPEG:M[Yy][Ee][Ss])
.include "../../multimedia/ffmpeg/buildlink3.mk"
.endif

.include "../../mk/bsd.pkg.mk"
