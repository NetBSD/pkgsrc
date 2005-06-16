# $NetBSD: Makefile,v 1.15 2005/06/16 06:57:50 jlam Exp $

DISTNAME=	fMSX24.tar
PKGNAME=	fmsx-2.4
CATEGORIES=	emulators x11
MASTER_SITES=	http://www.komkon.org/fms/fMSX/
EXTRACT_SUFX=	.Z

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.komkon.org/fms/fMSX/
COMMENT=	MSX (Z80-based computer) emulator

RESTRICTED=		"ROM image copyright is questionable"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

WRKSRC= 	${WRKDIR}/MSX

.include "../../mk/bsd.prefs.mk"
USE_SUN_AUDIO?=	YES
DEFS=		-DFontDir=\"\\\"${PREFIX}/share/fmsx/\"\\\"
DEFS+=		-DRomDir=\"\\\"${PREFIX}/share/fmsx/\"\\\"
DEFS+=		-DMITSHM -D${CUR_DEPTH} -DSOUND
.if ${USE_SUN_AUDIO} == "YES"
DEFS+=		-DSUN_AUDIO
.endif

MAKE_ENV=	DEFS="${DEFS}"

INSTALLATION_DIRS=	bin

.include "../../mk/x11.buildlink3.mk"

post-extract:
	@${RM} ${WRKSRC}/CMOS.ROM
	@${CHMOD} -R a+r ${WRKSRC}

pre-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/share/fmsx
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html

# Makefile of fMSX doesn't have install target.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fmsx ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rddsk ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/wrdsk ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.ROM ${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/fMSX.html ${PREFIX}/share/doc/html

.include "../../mk/bsd.pkg.mk"

# XXX It would be nice to customize for each user's display, but this
#     way of doing it at build time depending on build environment is wrong.
#.ifdef DISPLAY
#CUR_DEPTH!=	( xwininfo -display ${DISPLAY} -root | fgrep Depth: | ${SED} 's-.*Depth: -BPP-' )
#.else
CUR_DEPTH= BPP8
#.endif
