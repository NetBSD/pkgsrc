# $NetBSD: Makefile,v 1.9 2003/04/16 15:27:36 dillo Exp $
#

DISTNAME=	w32codec-0.90pre7
PKGNAME=	win32-codecs-020909
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://mplayerhq.hu/MPlayer/releases/codecs/
MASTER_SITES+=	http://ftp.kde.com/support/Multimedia/Video/Players/MPlayer/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} qt6dlls.tar.bz2 dmocodecs.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mplayerhq.hu/MPlayer/releases/codecs/
COMMENT=	huge compilation of Win32 binary codecs

SITES_qt6dlls.tar.bz2=	http://www.mplayerhq.hu/~alex/codecs/
SITES_dmocodecs.tar.bz2=	ftp://mplayerhq.hu/MPlayer/releases/codecs/

ONLY_FOR_PLATFORM=	*-*-i386

NO_BUILD=	YES

RESTRICTED=	"Unsure of codec's license"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=  ${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME:C/pre.*//}/* ${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKDIR}/qt6dlls/* ${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKDIR}/dmocodecs/* ${PREFIX}/lib/win32

.include "../../mk/bsd.pkg.mk"
