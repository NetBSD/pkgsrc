# $NetBSD: Makefile,v 1.5 2001/12/30 21:44:25 agc Exp $
#

DISTNAME=		xm71010s
PKGNAME=		xm7-1010s
CATEGORIES=		emulators
MASTER_SITES=		http://www.ipc-tokai.or.jp/~ytanaka/fm7/
EXTRACT_SUFX=		.lzh

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.ipc-tokai.or.jp/~ytanaka/fm7/xm7.shtml
COMMENT=		X11-based FM-7 emulator

BUILD_DEPENDS+=		nkf-1.7:../../japanese/nkf

WRKSRC=			${WRKDIR}/vm
RESTRICTED=		source archive is not redistributable
RESTRICTED+=		no-commercial-use
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

LHA=			lha
# convert CRLF to LF and sjis encoding to EUC-JP in text files.
EXTRACT_CMD=		${LHA} xqte ${DOWNLOADED_DISTFILE}

NO_CONFIGURE=		yes
MAKEFILE=		makefile.x11

post-extract:
	@cd ${WRKDIR}; ${MV} linux/* vm

pre-build:
	cd ${WRKSRC}; ${MV} cpu.c cpu.c-msdos && ${SED} -e 's|.$$||g' cpu.c-msdos > cpu.c

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/vm/xm7 ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
