# $NetBSD: Makefile,v 1.4 2023/11/12 13:21:20 wiz Exp $

DISTNAME=	advancemame-3.9
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=amadvance/}
GITHUB_PROJECT=	advancemame
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.advancemame.it/
COMMENT=	Arcade game emulator with advanced video support
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	egrep zip gzip pkg-config ksh gmake
USE_LANGUAGES=	c c++

CONFIG_SHELL=	ksh

TOOL_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

CONFIGURE_ARGS+=	--enable-expat
CONFIGURE_ARGS+=	--enable-zlib
CONFIGURE_ARGS+=	--enable-sdl2
CONFIGURE_ARGS+=	--disable-sdl

# i386-only, probably requires an external assembler
# not tested
CONFIGURE_ARGS+=	--disable-asm
CONFIGURE_ARGS+=	--disable-asm-mips3

CONFIGURE_ARGS+=	--prefix=${DESTDIR}${PREFIX}

.include "../../mk/pthread.buildlink3.mk"

.if defined(PTHREAD_TYPE) && ${PTHREAD_TYPE} != "none"
CONFIGURE_ARGS+=	--enable-pthread
.else
CONFIGURE_ARGS+=	--disable-pthread
.endif

.include "../../mk/oss.buildlink3.mk"

.if defined(OSS_TYPE) && ${OSS_TYPE} != "none"
CONFIGURE_ARGS+=	--enable-oss
LDFLAGS+=		${BUILDLINK_LDADD.oss}
.else
CONFIGURE_ARGS+=	--disable-oss
.endif

.if ${OPSYS} == "Linux"
ADVMAME_OPSYS=	linux
.elif ${OPSYS} == "Darwin"
ADVMAME_OPSYS=	darwin
.else
ADVMAME_OPSYS=	generic
.endif

ICON_SIZES=	16 32 48 256

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/doc/advancemame
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/advance
INSTALLATION_DIRS+=	share/advance/rom
INSTALLATION_DIRS+=	share/advance/sample
INSTALLATION_DIRS+=	share/advance/artwork
INSTALLATION_DIRS+=	share/advance/image
INSTALLATION_DIRS+=	share/advance/image/ti99_4a
INSTALLATION_DIRS+=	share/advance/crc
INSTALLATION_DIRS+=	share/advance/snap
INSTALLATION_DIRS+=	share/advance/snap/ti99_4a
INSTALLATION_DIRS+=	share/applications
.for size in ${ICON_SIZES}
INSTALLATION_DIRS+=	share/icons/hicolor/${size}x${size}/apps
.endfor

MANPAGES=	advcfg.1 advdev.1 advj.1 advk.1 advm.1 advmame.1 \
		advmenu.1 advs.1 advv.1

HTMLDOCS=	authors.html build.html carddos.html cardlinx.html \
		cardwin.html cost.html faq.html history.html install.html \
		readme.html release.html script.html svgawin.html

post-configure:
	# Sigh... avoid a conflict with an internal header.
	${RM} -f ${BUILDLINK_DIR}/include/png.h
	${PREFIX}/bin/convert ${WRKSRC}/contrib/logo/megaman.ico[2] \
	    ${WRKDIR}/advancemame-48.png
	${PREFIX}/bin/convert ${WRKSRC}/contrib/logo/megaman.ico[3] \
	    ${WRKDIR}/advancemame-32.png
	${PREFIX}/bin/convert ${WRKSRC}/contrib/logo/megaman.ico[4] \
	    ${WRKDIR}/advancemame-16.png
	${PREFIX}/bin/convert ${WRKSRC}/contrib/logo/megaman.ico[5] \
	    ${WRKDIR}/advancemame-256.png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/obj/mame/${ADVMAME_OPSYS}/blend/advmame \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/obj/mess/${ADVMAME_OPSYS}/blend/advmess \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/obj/menu/${ADVMAME_OPSYS}/blend/advmenu \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/obj/s/${ADVMAME_OPSYS}/blend/advs \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/obj/k/${ADVMAME_OPSYS}/blend/advk \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/obj/j/${ADVMAME_OPSYS}/blend/advj \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/obj/m/${ADVMAME_OPSYS}/blend/advm \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/advancemame.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
.for size in ${ICON_SIZES}
	${INSTALL_DATA} ${WRKDIR}/advancemame-${size}.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${size}x${size}/apps/advancemame.png
.endfor
.for file in ${MANPAGES}
	${INSTALL_MAN} ${WRKSRC}/doc/${file} \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endfor
.for file in ${HTMLDOCS}
	${INSTALL_MAN} ${WRKSRC}/doc/${file} \
	    ${DESTDIR}${PREFIX}/share/doc/advancemame
.endfor

.include "options.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
