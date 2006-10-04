# $NetBSD: Makefile,v 1.22 2006/10/04 21:38:37 wiz Exp $

DISTNAME=	fMSX24.tar
PKGNAME=	fmsx-2.4
PKGREVISION=	1
CATEGORIES=	emulators x11
MASTER_SITES=	http://fms.komkon.org/fMSX/
EXTRACT_SUFX=	.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fms.komkon.org/fMSX/
COMMENT=	MSX (Z80-based computer) emulator

RESTRICTED=		ROM image copyright is questionable
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

WRKSRC= 	${WRKDIR}/MSX

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS"
USE_SUN_AUDIO?=	YES
.else
USE_SUN_AUDIO?=	NO
.endif
DEFS=		-DFontDir=\"${PREFIX:Q}/share/fmsx/\"
DEFS+=		-DRomDir=\"${PREFIX:Q}/share/fmsx/\"
DEFS+=		-DMITSHM -D${CUR_DEPTH} -DSOUND
.if ${USE_SUN_AUDIO} == "YES"
DEFS+=		-DSUN_AUDIO
.endif

MAKE_ENV+=	DEFS=${DEFS:Q}

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
