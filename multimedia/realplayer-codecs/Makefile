# $NetBSD: Makefile,v 1.15 2007/12/15 15:18:57 heinz Exp $
#

DISTNAME=	rp8codecs${RP_ARCH}-20050115
PKGNAME=	realplayer-codecs-8.20050115
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://www4.mplayerhq.hu/MPlayer/releases/codecs/ \
		ftp://ftp2.mplayerhq.hu/MPlayer/releases/codecs/ \
		ftp://ftp5.mplayerhq.hu/MPlayer/releases/codecs/ \
		http://www1.mplayerhq.hu/MPlayer/releases/codecs/ \
		http://www2.mplayerhq.hu/MPlayer/releases/codecs/
EXTRACT_SUFX=	.tar.bz2
# for easier 'make mdi'
#DISTFILES=	rp8codecs-20040626.tar.bz2 rp8codecs-ppc-20050115.tar.bz2 rp8codecs-alpha-20050115.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mplayerhq.hu/MPlayer/releases/codecs/
COMMENT=	RealPlayer 8 shared libraries, primarily for use with MPlayer

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	*-*-i386 *-*-powerpc *-*-alpha

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
RP_ARCH=
# The distfile has not been updated.
DISTFILES=	rp8codecs-20040626.tar.bz2
WRKSRC=		${WRKDIR}/rp8codecs-20040626
.elif ${MACHINE_ARCH} == "powerpc"
RP_ARCH=	-ppc
.elif ${MACHINE_ARCH} == "alpha"
RP_ARCH=	-alpha
.endif

NO_BUILD=	YES

RESTRICTED=	Unsure of codec's license
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}
NO_SRC_ON_CDROM=${RESTRICTED}
NO_SRC_ON_FTP=	${RESTRICTED}

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR:Q}${PREFIX}/lib/RealPlayer8-Codecs
	${INSTALL_LIB} ${WRKSRC}/*.so.*.* \
		${DESTDIR:Q}${PREFIX}/lib/RealPlayer8-Codecs

.include "../../mk/bsd.pkg.mk"
