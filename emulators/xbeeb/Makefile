# $NetBSD: Makefile,v 1.28 2012/10/03 12:55:21 asau Exp $
#

DISTNAME=	xbeeb-0.4.1
PKGREVISION=	1
CATEGORIES=	emulators x11
MASTER_SITES=	http://bbc.nvg.org/emul/Xbeeb/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://www.cloud9.co.uk/james/BBCMicro/Xbeeb/
COMMENT=	Acorn BBC Micro emulator with an X based interface

USE_IMAKE=	yes
USE_TOOLS+=	bdftopcf xmkmf mkfontdir
MAN_PAGE=	${WRKDIR}/xbeeb.1

XBEEBROOT=	share/xbeeb
MESSAGE_SUBST+=	XBEEBROOT=${XBEEBROOT}
PLIST_SUBST+=	XBEEBROOT=${XBEEBROOT:Q}

FONTS_DIRS.x11=	${PREFIX}/lib/X11/fonts/xbeeb
REQD_DIRS=	${PREFIX}/lib/X11/fonts/xbeeb

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "options.mk"

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"

SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	post-patch
SUBST_MESSAGE.dsp=	Adjusting sound device path
SUBST_FILES.dsp=	src/SoundOSS.c
SUBST_SED.dsp=		-e "s|\"/dev/dsp\"|\"${DEVOSSAUDIO}\"|"

SUBST_CLASSES+=		osslib
SUBST_STAGE.osslib=	post-patch
SUBST_MESSAGE.osslib=	Linking OSS library
SUBST_FILES.osslib=	src/Imakefile
SUBST_SED.osslib=	-e "s|\\(SYS_LIBRARIES[	 ]*=.*\\)|\\1 ${LIBOSSAUDIO}|"

.else

SUBST_CLASSES+=		nooss
SUBST_STAGE.nooss=	post-patch
SUBST_MESSAGE.nooss=	Disabling sound support: No OSS on this platform
SUBST_FILES.nooss=	src/Config.h
SUBST_SED.nooss=	-e "s|^\#define\\([	 ]*SOUND_OSS.*\\)\$$|\#undef\\1|"

.endif # OSS_TYPE

SUBST_CLASSES+=		beebroot
SUBST_STAGE.beebroot=	post-patch
SUBST_MESSAGE.beebroot=	Adjusting XBEEBROOT path
SUBST_FILES.beebroot=	src/Config.h
SUBST_SED.beebroot=	-e "s|^\\(\#define[	 ]*XBEEBROOT[	 ]*\\)[^	 ].*\$$|\\1\"${PREFIX}/${XBEEBROOT}/\"|"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${XBEEBROOT}/roms ${XBEEBROOT}/docs lib/X11/fonts/xbeeb

# xbeeb build starts in the source directory
do-configure:
	cd ${WRKSRC}/src && xmkmf

post-patch:
	sed	-e 's+@XBEEBROOT@+${XBEEBROOT}+g' \
		-e 's+@PREFIX@+${PREFIX}+g' \
		${FILESDIR}/xbeeb.1 > ${MAN_PAGE}

do-build:
	cd ${WRKSRC}/src && env ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} xbeeb
	set -e; \
	cd ${WRKSRC}/fonts; \
	for i in *.bdf; do \
		${TOOLS_PATH.bdftopcf} "$$i" -o `${BASENAME} "$$i" .bdf`.pcf; \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xbeeb ${DESTDIR}${PREFIX}/bin/xbeeb
	${INSTALL_MAN} ${MAN_PAGE} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xbeeb.1
	${INSTALL_DATA} ${WRKSRC}/roms/xdfs0.90.rom ${DESTDIR}${PREFIX}/${XBEEBROOT}/roms/xdfs0.90.rom
	cd ${WRKSRC}/doc && ${INSTALL_DATA} * ${DESTDIR}${PREFIX}/${XBEEBROOT}/docs
	cd ${WRKSRC}/fonts && ${INSTALL_DATA} *.pcf ${DESTDIR}${PREFIX}/lib/X11/fonts/xbeeb

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
