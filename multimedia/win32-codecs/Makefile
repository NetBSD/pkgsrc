# $NetBSD: Makefile,v 1.3 2004/06/26 16:14:42 grant Exp $
#

DISTNAME=	win32codecs-20040626
PKGNAME=	win32-codecs-040626
CATEGORIES=	multimedia
MASTER_SITES=	http://www.mplayerhq.hu/MPlayer/releases/codecs/ \
		http://www2.mplayerhq.hu/MPlayer/releases/codecs/ \
		ftp://ftp.mplayerhq.hu/MPlayer/releases/codecs/ \
		ftp://ftp2.mplayerhq.hu/MPlayer/releases/codecs/
EXTRACT_SUFX=	.tar.bz2
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	qt6dlls-20040626.tar.bz2
DISTFILES+=	qtextras-20040626.tar.bz2
DISTFILES+=	rp9win32codecs-20040626.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mplayerhq.hu/MPlayer/releases/codecs/
COMMENT=	Huge compilation of Win32 binary codecs

USE_LANGUAGES=	# empty

ONLY_FOR_PLATFORM=	*-*-i386

NO_BUILD=	YES

RESTRICTED=	"Unsure of codec's license"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=  ${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/* ${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKDIR}/qt6dlls-20040626/* ${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKDIR}/qtextras/* ${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKDIR}/rp9win32codecs/*.dll ${PREFIX}/lib/win32

.include "../../mk/bsd.pkg.mk"
