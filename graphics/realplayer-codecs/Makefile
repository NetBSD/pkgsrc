# $NetBSD: Makefile,v 1.1.1.1 2003/04/01 08:02:48 mrg Exp $
#

DISTNAME=	rp8codecs${RP_ARCH}
PKGNAME=	realplayer-codecs
CATEGORIES=	graphics
MASTER_SITES=	ftp://mplayerhq.hu/MPlayer/releases/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

CONFLICTS=	realplayer-*

.if ${MACHINE_ARCH} == "i386"
RP_ARCH=
.elif ${MACHINE_ARCH} == "powerpc"
RP_ARCH=	-ppc
.elif ${MACHINE_ARCH} == "alpha"
RP_ARCH=	-alpha
.endif

MAINTAINER=	packages@netbsd.org
COMMENT=	RealPlayer 8 shared libraries, primary for use with MPlayer

USE_BUILDLINK2=	yes
NO_BUILD=	yes

ONLY_FOR_PLATFORM= NetBSD-*-i386 NetBSD-*-powerpc NetBSD-*-alpha

RESTRICTED=     "Unsure of codec's license"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=  ${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/RealPlayer8/Codecs
	${INSTALL_DATA} ${WRKSRC}/* ${PREFIX}/lib/RealPlayer8/Codecs
.if ${MACHINE_ARCH} == "powerpc"
	${LN} -s /usr/lib/libc.so /usr/pkg/lib/libc.so.6
.endif

.include "../../mk/bsd.pkg.mk"
