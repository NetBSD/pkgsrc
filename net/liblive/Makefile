# $NetBSD: Makefile,v 1.13 2006/07/31 21:08:03 rillig Exp $
#

DISTNAME=	live.2003.04.04
PKGNAME=	lib${DISTNAME:S/./-/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.live.com/liveMedia/public/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.live.com/liveMedia/
COMMENT=	Set of C++ libraries for multimedia streaming

WRKSRC=		${WRKDIR}/live
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES

INSTALLATION_DIRS=	bin lib

do-configure:
	${CP} ${FILESDIR}/config.netbsd ${WRKSRC}
	${CP} ${FILESDIR}/config.netbsd ${WRKSRC}/config.dragonfly
	cd ${WRKSRC} && ${SH} ./genMakefiles ${LOWER_OPSYS}
	${RM} -f ${WRKSRC}/testProgs/qtParse

do-install:
.for lib in BasicUsageEnvironment UsageEnvironment groupsock liveMedia
	cd ${WRKSRC}/${lib} &&						\
	${LIBTOOL} --mode=install ${INSTALL_DATA} lib${lib}.la ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include/liblive/${lib}
	cd ${WRKSRC}/${lib}/include &&					\
	for i in *.h *.hh ; do						\
		[ ! -f $$i ] ||						\
		${INSTALL_DATA} $$i ${PREFIX}/include/liblive/${lib} ;	\
	done
.endfor
.for bin in openRTSP playSIP qtParse sapWatch testMP3Receiver		\
	testMP3Streamer testMPEGAudioVideoStreamer testMPEGSplitter	\
	testMPEGVideoReceiver testMPEGVideoStreamer testRelay vobStreamer
	cd ${WRKSRC}/testProgs &&					\
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${bin} ${PREFIX}/bin
.endfor

.include "../../mk/bsd.pkg.mk"
