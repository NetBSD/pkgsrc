# $NetBSD: Makefile,v 1.21 2003/11/22 23:55:15 jlam Exp $
#

DISTNAME=	atari800-1.3.0
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=atari800/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} xf25.zip

EXTRACT_CMD_OPTS.zip=	-Lqo

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://atari800.atari.org
COMMENT=	Atari 8-bit computer, 5200 console emulator

RESTRICTED=		"copyrighted ROM images"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

BUILD_DIRS=	${WRKSRC}/build ${WRKSRC}/build-shm ${WRKSRC}/build-curses

MAKE_FLAGS=	LDFLAGS="${LDFLAGS} -L${X11BASE}/lib" \
		CFLAGS="-c ${CFLAGS} -DDEVOSSAUDIO=\\\"${DEVOSSAUDIO}\\\" -DPREFIX=\\\"${PREFIX}\\\""
#override HOME to avoid picking up a bad ${HOME}/.atari800 during the build
MAKE_FLAGS+=	HOME=${WRKSRC}

post-extract:
	@cd ${WRKDIR} && ${LOCALBASE}/bin/unzip -Lqo ${DISTDIR}/xf25.zip
	${SED} -e 's,@PREFIX@,${PREFIX},g' <${FILESDIR}/atari800.cfg \
                >${WRKSRC}/atari800.cfg
	mkdir ${BUILD_DIRS}

do-configure:
	@cd ${WRKSRC}/build-shm && LDFLAGS="${LDFLAGS} -s ${X11_LDFLAGS}" LIBS=${LIBOSSAUDIO} ../configure --prefix=${PREFIX} --with-x --enable-MONITOR_BREAK  --enable-MONITOR_HINTS --enable-MONITOR_ASSEMBLER  --enable-SOUND --enable-SET_LED --target=x11-shm --srcdir=..
	@${ECHO} '#define PREFIX "${PREFIX}"' >> ${WRKSRC}/build-shm/config.h
	@cd ${WRKSRC}/build-curses && LDFLAGS="-s ${LDFLAGS}" LIBS=${LIBOSSAUDIO} ../configure --prefix=${PREFIX} --enable-MONITOR_BREAK  --enable-MONITOR_HINTS --enable-MONITOR_ASSEMBLER  --enable-SOUND --enable-SET_LED --target=curses --srcdir=..
	@${ECHO} '#define PREFIX "${PREFIX}"' >> ${WRKSRC}/build-curses/config.h
	@cd ${WRKSRC}/build && LDFLAGS="-s ${LDFLAGS} ${X11_LDFLAGS}" LIBS=${LIBOSSAUDIO} ../configure --prefix=${PREFIX} --with-x --enable-MONITOR_BREAK  --enable-MONITOR_HINTS --enable-MONITOR_ASSEMBLER  --enable-SOUND --enable-SET_LED --target=x11 --srcdir=..
	@${ECHO} '#define PREFIX "${PREFIX}"' >> ${WRKSRC}/build/config.h

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/atari800
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/atari800
	${INSTALL_PROGRAM} ${WRKSRC}/build-shm/atari800 ${PREFIX}/bin/atari800-shm
	${INSTALL_PROGRAM} ${WRKSRC}/build-curses/atari800 ${PREFIX}/bin/atari800-curses
	${INSTALL_PROGRAM} ${WRKSRC}/build/atari800 ${PREFIX}/bin/atari800
	${INSTALL_DATA} ${WRKDIR}/*.rom ${WRKDIR}/*.xfd ${WRKDIR}/*.atr \
		${WRKSRC}/atari800.cfg ${PREFIX}/share/atari800/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/DOC/README \
		${WRKDIR}/${DISTNAME}/DOC/USAGE \
		${PREFIX}/share/doc/atari800
	${INSTALL_DATA} ${WRKSRC}/atari800.man ${PREFIX}/man/man1/atari800.1

.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
