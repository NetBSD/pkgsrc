# $NetBSD: Makefile,v 1.3 2001/02/28 10:47:23 wiz Exp $
#

DISTNAME=		xm71010s
PKGNAME=		xm7-1010s
CATEGORIES=		emulators
MASTER_SITES=		http://www.ipc-tokai.or.jp/~ytanaka/fm7/
EXTRACT_SUFX=		.lzh

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.ipc-tokai.or.jp/~ytanaka/fm7/xm7.shtml
COMMENT=		X11-based FM-7 emulator

BUILD_DEPENDS+=		nkf:../../japanese/nkf

WRKSRC=			${WRKDIR}/vm
RESTRICTED=		source archive is not redistributable
RESTRICTED+=		no-commercial-use
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

LHA=			lha
# convert CRLF to LF and sjis encoding to EUC-JP in text files.
EXTRACT_CMD=		${LHA} xqte ${DOWNLOADED_DISTFILE}

NO_CONFIGURE=		yes
MAKEFILE=		Makefile.X11

post-extract:
	@cd ${WRKDIR}; ${MV} linux/* vm

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/vm/xm7 ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
