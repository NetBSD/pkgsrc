# $NetBSD: Makefile,v 1.5 2002/11/16 14:05:53 wiz Exp $
#

DISTNAME=	w32codec-0.90pre7
PKGNAME=	win32-codecs-020909
WRKSRC=		${WRKDIR}/${DISTNAME:C/pre.*//}
CATEGORIES=	graphics
MASTER_SITES=	ftp://mplayerhq.hu/MPlayer/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	zuntum@netbsd.org
COMMENT=	huge compilation of Win32 binary codecs

USE_BUILDLINK2=	yes
NO_BUILD=	yes

ONLY_FOR_PLATFORM= NetBSD-*-i386

RESTRICTED=     "Unsure of codec's license"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=  ${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKSRC}/* ${PREFIX}/lib/win32

.include "../../mk/bsd.pkg.mk"
