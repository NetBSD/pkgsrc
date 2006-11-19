# $NetBSD: Makefile,v 1.14 2006/11/19 22:36:20 rillig Exp $
#

DISTNAME=	live.2006.11.16a
PKGNAME=	lib${DISTNAME:S/./-/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.live555.com/liveMedia/public/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.live555.com/liveMedia/
COMMENT=	Set of C++ libraries for multimedia streaming

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
	${LIBTOOL} --mode=install ${INSTALL_DATA} lib${lib}.la ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include/liblive/${lib}
	cd ${WRKSRC}/${lib}/include &&					\
	for i in *.h *.hh ; do						\
		[ ! -f $$i ] ||						\
		${INSTALL_DATA} $$i ${PREFIX}/include/liblive/${lib} ;	\
	done
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/liblive
.for bin in testMP3Streamer testMPEG1or2VideoStreamer 			\
	testMPEG1or2AudioVideoStreamer testMPEG2TransportStreamer 	\
	testMPEG4VideoStreamer testWAVAudioStreamer testAMRAudioStreamer\
	vobStreamer testMP3Receiver testMPEG1or2VideoReceiver sapWatch 	\
	testRelay testOnDemandRTSPServer testMPEG1or2AudioVideoToDarwin \
	testMPEG4VideoToDarwin  openRTSP playSIP testMPEG1or2Splitter 	\
	testMPEG1or2ProgramToTransportStream
	cd ${WRKSRC}/testProgs &&					\
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} 			\
		${bin} ${PREFIX}/share/examples/liblive
.endfor

.include "../../mk/bsd.pkg.mk"
