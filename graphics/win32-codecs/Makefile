# $NetBSD: Makefile,v 1.2 2001/09/27 23:18:13 jlam Exp $
#

DISTNAME=	binaries-${CODEC_VERSION}
PKGNAME=	win32-codecs-${CODEC_VERSION}
CATEGORIES=	graphics
MASTER_SITES=	http://ernie.eit.uni-kl.de/avifile/		\
		http://divx.euro.ru/				\
		http://www.toon.eu.org/divx/
DISTFILES=	${DISTNAME}.zip wmvds32.ax.gz

MAINTAINER=	zuntum@netbsd.org
COMMENT=	Huge compilation of Win32 binary codecs, including MPEG-4(DivX ;-))

BUILD_DEPENDS=	unzip-[0-9]*:../../archivers/unzip

EXTRACT_ONLY=	#

NO_BUILD=	yes

ONLY_FOR_PLATFORM= NetBSD-*-i386

RESTRICTED=     "Unsure of codec's license"
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=  ${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

CODEC_VERSION=	010122

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/win32
	${LOCALBASE}/bin/unzip ${DISTDIR}/binaries-${CODEC_VERSION}.zip \
		-d ${PREFIX}/lib/win32
	${GZCAT} ${DISTDIR}/wmvds32.ax.gz > ${PREFIX}/lib/win32/wmvds32.ax
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/lib/win32

.include "../../mk/bsd.pkg.mk"
