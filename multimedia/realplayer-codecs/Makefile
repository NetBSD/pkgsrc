# $NetBSD: Makefile,v 1.1.1.1 2004/01/26 12:04:15 jmmv Exp $
#

DISTNAME=	rp8codecs${RP_ARCH}
PKGNAME=	realplayer-codecs-8
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	ftp://mplayerhq.hu/MPlayer/releases/codecs/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mplayerhq.hu/MPlayer/releases/codecs/
COMMENT=	RealPlayer 8 shared libraries, primarily for use with MPlayer

ONLY_FOR_PLATFORM=	*-*-i386 *-*-powerpc *-*-alpha

.if ${MACHINE_ARCH} == "i386"
RP_ARCH=
.elif ${MACHINE_ARCH} == "powerpc"
RP_ARCH=	-ppc
.elif ${MACHINE_ARCH} == "alpha"
RP_ARCH=	-alpha
.endif

NO_BUILD=	YES

RESTRICTED=	"Unsure of codec's license"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/RealPlayer8-Codecs
	${INSTALL_DATA} ${WRKSRC}/* ${PREFIX}/lib/RealPlayer8-Codecs

.include "../../mk/bsd.pkg.mk"
