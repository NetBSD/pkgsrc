# $NetBSD: Makefile,v 1.6 2002/12/21 19:44:28 wiz Exp $
#

DISTNAME=	w32codec-0.90pre7
PKGNAME=	win32-codecs-020909
PKGREVISION=	1
WRKSRC=		${WRKDIR}
CATEGORIES=	graphics
MASTER_SITES=	ftp://mplayerhq.hu/MPlayer/releases/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} qt6dlls.tar.bz2

MAINTAINER=	packages@netbsd.org
COMMENT=	huge compilation of Win32 binary codecs

USE_BUILDLINK2=	yes
NO_BUILD=	yes

SITES_qt6dlls.tar.bz2=	http://www.mplayerhq.hu/~alex/codecs/

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

.include "../../mk/bsd.pkg.mk"
