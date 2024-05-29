# $NetBSD: Makefile,v 1.28 2024/05/29 16:31:24 adam Exp $

DISTNAME=	quodlibet-4.6.0
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=quodlibet/}
GITHUB_PROJECT=	quodlibet
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://quodlibet.readthedocs.io/
COMMENT=	Ex Falso / Quod Libet - Music Library / Editor / Player
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-feedparser<6.0.0:../../textproc/py-feedparser5
DEPENDS+=	${PYPKGPREFIX}-gstreamer1-[0-9]*:../../multimedia/py-gstreamer1
DEPENDS+=	${PYPKGPREFIX}-mutagen-[0-9]*:../../audio/py-mutagen
DEPENDS+=	gdk-pixbuf2-[0-9]*:../../graphics/gdk-pixbuf2
DEPENDS+=	gtk3+-[0-9]*:../../x11/gtk3

DEPENDS+=	gst-plugins1-flac-[0-9]*:../../audio/gst-plugins1-flac
DEPENDS+=	gst-plugins1-mpg123-[0-9]*:../../audio/gst-plugins1-mpg123
DEPENDS+=	gst-plugins1-ogg-[0-9]*:../../multimedia/gst-plugins1-ogg
DEPENDS+=	gst-plugins1-opus-[0-9]*:../../audio/gst-plugins1-opus
DEPENDS+=	gst-plugins1-vorbis-[0-9]*:../../audio/gst-plugins1-vorbis

.include "../../mk/oss.buildlink3.mk"

.if ${OPSYS} == "Linux"
DEPENDS+=	gst-plugins1-alsa-[0-9]*:../../audio/gst-plugins1-alsa
.endif

.if ${OPSYS} != "Linux" && ${OSS_TYPE} != "none"
DEPENDS+=	gst-plugins1-oss-[0-9]*:../../audio/gst-plugins1-oss
.endif

USE_TOOLS+=	msgfmt

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/* ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
