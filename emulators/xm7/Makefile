# $NetBSD: Makefile,v 1.6.2.1 2002/06/23 18:45:37 jlam Exp $
#

DISTNAME=		xm71010s
PKGNAME=		xm7-1010s
CATEGORIES=		emulators
MASTER_SITES=		http://www.ipc-tokai.or.jp/~ytanaka/fm7/
EXTRACT_SUFX=		.lzh

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.ipc-tokai.or.jp/~ytanaka/fm7/xm7.shtml
COMMENT=		X11-based FM-7 emulator

BUILD_DEPENDS+=		nkf-1.7:../../converters/nkf

WRKSRC=			${WRKDIR}/vm
RESTRICTED=		source archive is not redistributable
RESTRICTED+=		no-commercial-use
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

# convert CRLF to LF
EXTRACT_CMD=		lha xqt ${DOWNLOADED_DISTFILE}

NO_CONFIGURE=		yes
MAKEFILE=		makefile.x11

post-extract:
	@cd ${WRKDIR}; ${MV} linux/* vm

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/vm/xm7 ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
