# $NetBSD: Makefile,v 1.1.1.1 2000/07/28 15:54:26 martin Exp $

DISTNAME=	fMSX21.tar
PKGNAME=	fmsx-2.1
CATEGORIES=	emulators x11
MASTER_SITES=	http://www.komkon.org/fms/fMSX/
EXTRACT_SUFX=	.Z

MAINTAINER=	martin@netbsd.org
HOMEPAGE=	http://www.komkon.org/fms/fMSX/

RESTRICTED=		"ROM image copyright is questionable"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
MIRROR_DISTFILE=	no

USE_X11=	yes

WRKSRC= 	${WRKDIR}/MSX

DEFS=		-DFontDir=\"\\\"${PREFIX}/share/fmsx/\"\\\"
DEFS+=		-DRomDir=\"\\\"${PREFIX}/share/fmsx/\"\\\"
DEFS+=		-DMITSHM -D${CUR_DEPTH}

MAKE_ENV=	DEFS="${DEFS}"

pre-install:
	@${MKDIR} ${PREFIX}/share/fmsx \
		&& ${CHMOD} a+rx ${PREFIX}/share/fmsx
	@${MKDIR} ${PREFIX}/share/doc/html/fmsx \
		&& ${CHMOD} a+rx ${PREFIX}/share/doc/html/fmsx

# Makefile of fMSX doesn't have install target.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fmsx ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rddsk ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/wrdsk ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/CYRILLIC.FNT ${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/ITALIC.FNT ${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/DISK.ROM ${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/KANJI.ROM ${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/MSX.ROM ${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/MSX2.ROM ${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/MSX2EXT.ROM ${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/MSX2P.ROM ${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/MSX2PEXT.ROM ${PREFIX}/share/fmsx
	${INSTALL_DATA} ${WRKSRC}/PAINTER.ROM ${PREFIX}/share/fmsx
	${MKDIR} ${PREFIX}/share/doc/fmsx
	${INSTALL_DATA} ${WRKSRC}/fMSX.html ${PREFIX}/share/doc/fmsx

.include "../../mk/bsd.pkg.mk"

.ifdef DISPLAY
CUR_DEPTH!=	( xwininfo -display ${DISPLAY} -root | fgrep Depth: | ${SED} 's-.*Depth: -BPP-' )
.else
CUR_DEPTH= BPP8
.endif
