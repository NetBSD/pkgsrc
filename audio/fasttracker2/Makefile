# $NetBSD: Makefile,v 1.42 2019/10/03 01:44:00 fox Exp $

DISTNAME=	ft2-clone-v${PKGVERSION_NOREV}-code
PKGNAME=	fasttracker2-${DISTVERSION}
DISTVERSION=	1.00
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://16-bits.org/
EXTRACT_SUFX=	.zip

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://16-bits.org/
COMMENT=	Portable Fasttracker II clone in C using SDL 2
LICENSE=	modified-bsd AND cc-by-nc-sa-v4.0-license

WRKSRC=		${WRKDIR}/ft2-clone-code
USE_LANGUAGES=	c99 c++
USE_CMAKE=	yes

TOOL_DEPENDS+=	icoutils-[0-9]*:../../graphics/icoutils

ICON_SIZES=	16 24 32 48 64 128 256

LIBS.SunOS+=	-liconv

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/appdata
.for s in ${ICON_SIZES}
INSTALLATION_DIRS+=	share/icons/hicolor/${s}x${s}/apps
.endfor

SUBST_CLASSES+=		d2u
SUBST_MESSAGE.d2u=	Converting CRLF to LF.
SUBST_STAGE.d2u=	post-extract
SUBST_FILES.d2u=	CMakeLists.txt src/*.[ch]
SUBST_FILTER_CMD.d2u=	${TR} -d '\r'

pre-configure:
.for s in ${ICON_SIZES}
	cd ${WRKSRC} && ${PREFIX}/bin/icotool -w ${s} -h ${s} -x -o ${s}.png \
	    src/gfxdata/icon/ft2-clone.ico
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/other/ft2-clone \
		${DESTDIR}${PREFIX}/bin/${PKGBASE}
	${INSTALL_DATA} ${FILESDIR}/fasttracker2.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/fasttracker2.appdata.xml \
		${DESTDIR}${PREFIX}/share/appdata
.for s in ${ICON_SIZES}
	${INSTALL_DATA} ${WRKSRC}/${s}.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/fasttracker2.png
.endfor

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Linux"
BUILDLINK_TRANSFORM+=	rm:-lasound
.else
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
