# $NetBSD: Makefile,v 1.13 2005/01/27 23:53:13 ben Exp $
#

DISTNAME=	windows-all-20050115
PKGNAME=	win32-codecs-050115
CATEGORIES=	multimedia
MASTER_SITES=	http://www.mplayerhq.hu/MPlayer/releases/codecs/ \
		http://www2.mplayerhq.hu/MPlayer/releases/codecs/ \
		ftp://ftp.mplayerhq.hu/MPlayer/releases/codecs/
EXTRACT_SUFX=	.zip
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	qt65dlls-20040704.tar.bz2
DISTFILES+=	qtextras-20041107.tar.bz2
DISTFILES+=	rp9codecs-win32-20050115.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mplayerhq.hu/MPlayer/releases/codecs/
COMMENT=	Huge compilation of Win32 binary codecs

USE_LANGUAGES=	# empty

ONLY_FOR_PLATFORM=	*-*-i386

NO_BUILD=	# defined
NO_CONFIGURE=	# defined

RESTRICTED=	"Unsure of codec's license"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=  ${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/* ${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKDIR}/qt65dlls-20040704/* ${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKDIR}/qtextras-20041107/* ${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKDIR}/rp9codecs-win32-20050115/*.dll ${PREFIX}/lib/win32

.include "../../mk/bsd.pkg.mk"
