# $NetBSD: Makefile,v 1.1.1.1 2000/12/13 17:12:19 kei Exp $
#

DISTNAME=		xm71010s
PKGNAME=		xm7-1010s
CATEGORIES=		emulators
MASTER_SITES=		http://www.ipc-tokai.or.jp/~ytanaka/fm7/
EXTRACT_SUFX=		.lzh

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.ipc-tokai.or.jp/~ytanaka/fm7/xm7.shtml

NO_WRKSUBDIR=		# empty
WRKSRC=			${WRKDIR}/vm
RESTRICTED=		source archive is not redistributable
RESTRICTED+=		no-commercial-use
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}
MIRROR_DISTFILES=	no

LHA=			lha
# convert CRLF to LF and sjis encoding to EUC-JP in text files.
EXTRACT_CMD=		${LHA} xqte ${DOWNLOADED_DISTFILE} 

BUILD_DEPENDS+=		nkf:../../japanese/nkf
NO_CONFIGURE=		yes
MAKEFILE=		Makefile.X11

post-extract:
	@cd ${WRKDIR}; ${MV} linux/* vm

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/vm/xm7 ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
