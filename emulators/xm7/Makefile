# $NetBSD: Makefile,v 1.15 2006/01/21 18:57:41 jlam Exp $
#

DISTNAME=		xm71010s
PKGNAME=		xm7-1010s
CATEGORIES=		emulators
MASTER_SITES=		http://www.ipc-tokai.or.jp/~ytanaka/fm7/
EXTRACT_SUFX=		.lzh

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.ipc-tokai.or.jp/~ytanaka/fm7/xm7.shtml
COMMENT=		X11-based FM-7 emulator

BUILD_DEPENDS+=		nkf>=1.7:../../converters/nkf

RESTRICTED=		source archive is not redistributable
RESTRICTED+=		no-commercial-use
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

EXTRACT_OPTS_LHA=	qt	# convert CRLF to LF

WRKSRC=			${WRKDIR}/vm
NO_CONFIGURE=		yes
MAKEFILE=		makefile.x11
INSTALLATION_DIRS=	bin

.include "../../mk/x11.buildlink3.mk"

post-extract:
	@cd ${WRKDIR}; ${MV} linux/* vm

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/vm/xm7 ${PREFIX}/bin

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
