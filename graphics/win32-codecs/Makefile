# $NetBSD: Makefile,v 1.7 2003/03/17 21:05:01 wiz Exp $
#

DISTNAME=	w32codec-0.90pre7
PKGNAME=	win32-codecs-020909
PKGREVISION=	2
WRKSRC=		${WRKDIR}
CATEGORIES=	graphics
MASTER_SITES=	ftp://mplayerhq.hu/MPlayer/releases/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} qt6dlls.tar.bz2 dmocodecs.tar.bz2

MAINTAINER=	packages@netbsd.org
COMMENT=	huge compilation of Win32 binary codecs

USE_BUILDLINK2=	yes
NO_BUILD=	yes

SITES_qt6dlls.tar.bz2=	http://www.mplayerhq.hu/~alex/codecs/
SITES_dmocodecs.tar.bz2=	ftp://mplayerhq.hu/MPlayer/releases/codecs/

ONLY_FOR_PLATFORM= NetBSD-*-i386

RESTRICTED=     "Unsure of codec's license"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=  ${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME:C/pre.*//}/* ${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKSRC}/qt6dlls/* ${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKSRC}/dmocodecs/* ${PREFIX}/lib/win32

.include "../../mk/bsd.pkg.mk"
