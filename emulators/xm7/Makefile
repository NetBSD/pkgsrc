# $NetBSD: Makefile,v 1.20 2007/02/16 10:53:11 rillig Exp $
#

DISTNAME=		xm71010s
PKGNAME=		xm7-1010s
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://www.ipc-tokai.or.jp/~ytanaka/fm7/
EXTRACT_SUFX=		.lzh

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.ipc-tokai.or.jp/~ytanaka/fm7/xm7.shtml
COMMENT=		X11-based FM-7 emulator

BUILD_DEPENDS+=		nkf>=1.7:../../converters/nkf

RESTRICTED=		source archive is not redistributable
LICENSE=		no-commercial-use
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

EXTRACT_OPTS_LHA=	qt	# convert CRLF to LF

WRKSRC=			${WRKDIR}/vm
NO_CONFIGURE=		yes
MAKE_FILE=		makefile.x11
INSTALLATION_DIRS=	bin

post-extract:
	cd ${WRKDIR} && mv linux/* vm

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/vm/xm7 ${PREFIX}/bin

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
