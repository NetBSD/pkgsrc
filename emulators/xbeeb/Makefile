# $NetBSD: Makefile,v 1.20 2006/09/22 13:21:37 dsainty Exp $
#

DISTNAME=	xbeeb-0.4.1
PKGREVISION=	1
CATEGORIES=	emulators x11
MASTER_SITES=	http://bbc.nvg.org/emul/Xbeeb/ \
		http://www.getafile.com/cgi-bin/merlot/get/james/xbeeb/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://www.cloud9.co.uk/james/BBCMicro/Xbeeb/
COMMENT=	Acorn BBC Micro emulator with an X based interface

USE_IMAKE=	yes
MAN_PAGE=	${WRKDIR}/xbeeb.1

XBEEBROOT=	share/xbeeb
MESSAGE_SUBST+=	XBEEBROOT=${XBEEBROOT}
PLIST_SUBST+=	XBEEBROOT=${XBEEBROOT:Q}

FONTS_DIRS.x11=	${PREFIX}/lib/X11/fonts/xbeeb
REQD_DIRS=	${PREFIX}/lib/X11/fonts/xbeeb

INSTALLATION_DIRS=	bin man/man1

PKG_OPTIONS_VAR=	PKG_OPTIONS.xbeeb
PKG_SUPPORTED_OPTIONS=	mitshm
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

# The emulator can be compiled either to use MIT-SHM, or to not.
# Unfortunately it doesn't support both at once.
.if empty(PKG_OPTIONS:Mmitshm)
SUBST_CLASSES+=		nomitshm
SUBST_STAGE.nomitshm=	post-patch
SUBST_MESSAGE.nomitshm=	Disabling MIT-SHM
SUBST_FILES.nomitshm=	src/Config.h
SUBST_SED.nomitshm=	-e "s|\#define	*MITSHM|\#undef MITSHM|"
.endif


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

# xbeeb build starts in the source directory
do-configure:
	cd ${WRKSRC}/src && ${XMKMF_CMD}

post-patch:
	${SED} -e 's+@XBEEBROOT@+${XBEEBROOT}+g' \
		-e 's+@PREFIX@+${PREFIX}+g' \
		${FILESDIR}/xbeeb.1 > ${MAN_PAGE}

do-build:
	(cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} xbeeb)
	(cd ${WRKSRC}/fonts && \
	for i in *.bdf ; \
	do \
		bdftopcf $$i -o `${BASENAME} $$i .bdf`.pcf ; \
	done)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xbeeb ${PREFIX}/bin/xbeeb
	${INSTALL_MAN} ${MAN_PAGE} ${PREFIX}/man/man1/xbeeb.1
	${INSTALL_DATA_DIR} ${PREFIX}/${XBEEBROOT}
	${INSTALL_DATA_DIR} ${PREFIX}/${XBEEBROOT}/roms
	${INSTALL_DATA_DIR} ${PREFIX}/${XBEEBROOT}/docs
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/fonts/xbeeb
	${INSTALL_DATA} ${WRKSRC}/roms/xdfs0.90.rom ${PREFIX}/${XBEEBROOT}/roms/xdfs0.90.rom
	for docfile in ${WRKSRC}/doc/*; do \
		${INSTALL_DATA} $$docfile ${PREFIX}/${XBEEBROOT}/docs; \
	done
	${CP} ${WRKSRC}/fonts/*.pcf ${PREFIX}/lib/X11/fonts/xbeeb
	mkfontdir ${PREFIX}/lib/X11/fonts/xbeeb

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
