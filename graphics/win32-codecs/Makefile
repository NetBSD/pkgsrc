# $NetBSD: Makefile,v 1.16 2003/07/23 12:15:06 jmmv Exp $
#

DISTNAME=	win32codecs
PKGNAME=	win32-codecs-030714
CATEGORIES=	graphics
MASTER_SITES=	ftp://mplayerhq.hu/MPlayer/releases/codecs/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} qt6dlls.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mplayerhq.hu/MPlayer/releases/codecs/
COMMENT=	Huge compilation of Win32 binary codecs

ONLY_FOR_PLATFORM=	*-*-i386

DIST_SUBDIR=	${PKGNAME_NOREV}

NO_BUILD=	YES

RESTRICTED=	"Unsure of codec's license"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=  ${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/* ${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKDIR}/qt6dlls/* ${PREFIX}/lib/win32

.include "../../mk/bsd.pkg.mk"
