# $NetBSD: Makefile,v 1.1.1.1 1999/05/23 05:17:04 tv Exp $

DISTNAME=	Atari800-0.9.8
PKGNAME=	atari800-0.9.8
CATEGORIES=	emulators
MASTER_SITES=	http://cas3.zlin.vutbr.cz/~stehlik/a800/ \
		http://www.signus.demon.co.uk/Software/Portable/Atari800e/
DISTFILES=	a800s098.zip xf25.zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://cas3.zlin.vutbr.cz/~stehlik/a800.htm

BUILD_DEPENDS=	unzip:../../archivers/unzip

USE_X11=	yes
RESTRICTED=	"copyrighted ROM images"
MIRROR_DISTFILE=no

EXTRACT_CMD=	unzip -Loq ${DOWNLOADED_DISTFILE}
MAKE_FLAGS=	LDFLAGS="${LDFLAGS} -L${X11BASE}/lib" OBJ="atari_x11.o" \
		CFLAGS="-c ${CFLAGS} -DPREFIX=\\\"${PREFIX}\\\""

post-extract:
	@find ${WRKDIR} -type f -print | xargs ${CHMOD} 0644
	@${MV} ${WRKDIR}/atari800-0.9.8/* ${WRKSRC}/

do-build:
	@printf 'n\nn\ny\n' | (cd ${WRKSRC} && \
		${MAKE} ${MAKE_FLAGS} -f Makefile.unix config.h >/dev/null)
	@${RM} -f ${WRKSRC}/atari_x11.o
	@cd ${WRKSRC} && ${MAKE} CPPFLAGS="-I${X11BASE}/include -DSHM" \
		LDLIBS="-lX11 -lXext -lm -lossaudio" ${MAKE_FLAGS} \
		-f Makefile.unix atari800
	${MV} ${WRKSRC}/atari800 ${WRKSRC}/atari800-shm
	@${RM} -f ${WRKSRC}/atari_x11.o
	@cd ${WRKSRC} && ${MAKE} CPPFLAGS="-I${X11BASE}/include" \
		LDLIBS="-lX11 -lm -lossaudio" ${MAKE_FLAGS} \
		-f Makefile.unix atari800
	${SED} -e 's,@PREFIX@,${PREFIX},g' <${FILESDIR}/atari800.cfg \
		>${WRKSRC}/atari800.cfg

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/atari800 ${PREFIX}/share/doc/atari800
	${INSTALL_PROGRAM} ${WRKSRC}/atari800-shm ${WRKSRC}/atari800 \
		${PREFIX}/bin/
	${INSTALL_DATA} ${WRKDIR}/*.rom ${WRKDIR}/*.xfd ${WRKDIR}/*.atr \
		${WRKSRC}/atari800.cfg ${PREFIX}/share/atari800/
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/USAGE \
		${PREFIX}/share/doc/atari800
	${INSTALL_DATA} ${WRKSRC}/atari800.man ${PREFIX}/man/man1/atari800.1

.include "../../mk/bsd.pkg.mk"
