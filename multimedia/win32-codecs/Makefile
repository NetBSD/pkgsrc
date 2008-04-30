# $NetBSD: Makefile,v 1.30.4.1 2008/04/30 10:53:45 rtr Exp $

DISTNAME=	windows-all-20071007
PKGNAME=	win32-codecs-071007
CATEGORIES=	multimedia
MASTER_SITES=	http://www4.mplayerhq.hu/MPlayer/releases/codecs/ \
		ftp://ftp.mplayerhq.hu/MPlayer/releases/codecs/ \
		http://www1.mplayerhq.hu/MPlayer/releases/codecs/ \
		http://www2.mplayerhq.hu/MPlayer/releases/codecs/ \
		ftp://ftp5.mplayerhq.hu/MPlayer/releases/codecs/
EXTRACT_SUFX=	.zip
DISTFILES+=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	rp9codecs-win32-20050115.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mplayerhq.hu/MPlayer/releases/codecs/
COMMENT=	Huge compilation of Win32 binary codecs

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty

ONLY_FOR_PLATFORM=	*-*-i386

NO_BUILD=	yes
NO_CONFIGURE=	yes

LICENSE=	mplayer-codec-license
RESTRICTED=	Unsure of codec's license
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/* ${DESTDIR}${PREFIX}/lib/win32
	${INSTALL_DATA} ${WRKDIR}/rp9codecs-win32-20050115/*.dll \
		${DESTDIR}${PREFIX}/lib/win32

.include "../../mk/bsd.pkg.mk"
