# $NetBSD: Makefile,v 1.15 2008/04/26 11:38:43 obache Exp $
#

DISTNAME=	live.2008.04.09
PKGNAME=	lib${DISTNAME:S/./-/}
CATEGORIES=	net
MASTER_SITES=	http://www.live555.com/liveMedia/public/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.live555.com/liveMedia/
COMMENT=	Set of C++ libraries for multimedia streaming

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/live
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES

INSTALLATION_DIRS=	bin lib

do-configure:
	${CP} ${FILESDIR}/config.netbsd ${WRKSRC}
	${CP} ${FILESDIR}/config.netbsd ${WRKSRC}/config.dragonfly
	cd ${WRKSRC} && ${SH} ./genMakefiles ${LOWER_OPSYS}

do-install:
.for lib in BasicUsageEnvironment UsageEnvironment groupsock liveMedia
	cd ${WRKSRC}/${lib} &&						\
	${LIBTOOL} --mode=install ${INSTALL_LIB} lib${lib}.la ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/include/liblive/${lib}
	cd ${WRKSRC}/${lib}/include &&					\
	for i in *.h *.hh ; do						\
		[ ! -f $$i ] ||						\
		${INSTALL_DATA} $$i 					\
			${DESTDIR}${PREFIX}/include/liblive/${lib} ;	\
	done
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/liblive
.for bin in testMP3Streamer testMPEG1or2VideoStreamer 			\
	testMPEG1or2AudioVideoStreamer testMPEG2TransportStreamer 	\
	testMPEG4VideoStreamer testWAVAudioStreamer testAMRAudioStreamer\
	vobStreamer testMP3Receiver testMPEG1or2VideoReceiver sapWatch 	\
	testRelay testOnDemandRTSPServer testMPEG1or2AudioVideoToDarwin \
	testMPEG4VideoToDarwin  openRTSP playSIP testMPEG1or2Splitter 	\
	testMPEG1or2ProgramToTransportStream
	cd ${WRKSRC}/testProgs &&					\
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} 			\
		${bin} ${DESTDIR}${PREFIX}/share/examples/liblive
.endfor

.include "../../mk/bsd.pkg.mk"
