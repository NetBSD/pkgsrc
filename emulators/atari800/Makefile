# $NetBSD: Makefile,v 1.16 2002/12/06 21:06:19 cjep Exp $
#

DISTNAME=	atari800-1.2.5
WRKSRC=		${WRKDIR}/${DISTNAME}/src
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=atari800/}
DISTFILES=	atari800-1.2.5.tar.gz xf25.zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://atari800.atari.org
COMMENT=	Atari 8-bit computer, 5200 console emulator

BUILD_DEPENDS=	unzip-[0-9]*:../../archivers/unzip

RESTRICTED=		"copyrighted ROM images"
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_X11=		YES

EXTRACT_ONLY=	atari800-1.2.5.tar.gz
MAKE_FLAGS=	LDFLAGS="${LDFLAGS} -L${X11BASE}/lib" OBJ="atari_x11.o" \
		CFLAGS="-c ${CFLAGS} -DPREFIX=\\\"${PREFIX}\\\""
#override HOME to avoid picking up a bad ${HOME}/.atari800 during the build
MAKE_FLAGS+=	HOME=${WRKSRC}

post-extract:
	@cd ${WRKDIR} && ${LOCALBASE}/bin/unzip -Lqo ${DISTDIR}/xf25.zip

do-build:
	@cd ${WRKSRC} && LDFLAGS="-s -L${X11BASE}/lib -Wl,-R,${X11BASE}/lib" LIBS=-lossaudio ./configure --prefix=${PREFIX} --with-x --enable-MONITOR_BREAK  --enable-MONITOR_HINTS --enable-MONITOR_ASSEMBLER  --enable-SOUND --enable-SET_LED --target=x11-shm
	@${ECHO} '#define PREFIX "${PREFIX}"' >> ${WRKSRC}/config.h
	@cd ${WRKSRC} && ${GMAKE}
	${MV} ${WRKSRC}/atari800 ${WRKSRC}/atari800-shm
	@cd ${WRKSRC} && ${GMAKE} clean
	@cd ${WRKSRC} && LDFLAGS="-s" LIBS=-lossaudio ./configure --prefix=${PREFIX} --enable-MONITOR_BREAK  --enable-MONITOR_HINTS --enable-MONITOR_ASSEMBLER  --enable-SOUND --enable-SET_LED --target=curses
	@${ECHO} '#define PREFIX "${PREFIX}"' >> ${WRKSRC}/config.h
	@cd ${WRKSRC} && ${GMAKE}
	${MV} ${WRKSRC}/atari800 ${WRKSRC}/atari800-curses
	@cd ${WRKSRC} && ${GMAKE} clean
	@cd ${WRKSRC} && LDFLAGS="-s -L${X11BASE}/lib -Wl,-R,${X11BASE}/lib" LIBS=-lossaudio ./configure --prefix=${PREFIX} --with-x --enable-MONITOR_BREAK  --enable-MONITOR_HINTS --enable-MONITOR_ASSEMBLER  --enable-SOUND --enable-SET_LED --target=x11
	@${ECHO} '#define PREFIX "${PREFIX}"' >> ${WRKSRC}/config.h
	@cd ${WRKSRC} && ${GMAKE}
	${SED} -e 's,@PREFIX@,${PREFIX},g' <${FILESDIR}/atari800.cfg \
		>${WRKSRC}/atari800.cfg

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/atari800
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/atari800
	${INSTALL_PROGRAM} ${WRKSRC}/atari800-shm ${WRKSRC}/atari800 \
		${WRKSRC}/atari800-curses ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKDIR}/*.rom ${WRKDIR}/*.xfd ${WRKDIR}/*.atr \
		${WRKSRC}/atari800.cfg ${PREFIX}/share/atari800/
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/DOC/README \
		${WRKDIR}/${DISTNAME}/DOC/USAGE \
		${PREFIX}/share/doc/atari800
	${INSTALL_DATA} ${WRKSRC}/atari800.man ${PREFIX}/man/man1/atari800.1

.include "../../mk/bsd.pkg.mk"
