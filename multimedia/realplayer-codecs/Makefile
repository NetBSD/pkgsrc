# $NetBSD: Makefile,v 1.3 2005/03/17 13:55:42 wiz Exp $
#

DISTNAME=	rp8codecs${RP_ARCH}-20040626
PKGNAME=	realplayer-codecs-8.20050115
CATEGORIES=	multimedia
MASTER_SITES=	ftp://mplayerhq.hu/MPlayer/releases/codecs/
EXTRACT_SUFX=	.tar.bz2
# for easier 'make mdi'
#DISTFILES=	rp8codecs-20040626.tar.bz2 rp8codecs-ppc-20050115.tar.bz2 rp8codecs-alpha-20050115.tar.bz2

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
