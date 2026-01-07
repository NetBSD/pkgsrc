# $NetBSD: Makefile,v 1.41 2026/01/07 08:45:54 wiz Exp $

DISTNAME=	quodlibet-4.6.0
PKGREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=quodlibet/}
GITHUB_PROJECT=	quodlibet
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://quodlibet.readthedocs.io/
COMMENT=	Ex Falso / Quod Libet - Music Library / Editor / Player
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
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

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	non_darwin

.if ${OPSYS} != "Darwin"
PLIST.non_darwin=	yes
.endif

.include "../../mk/oss.buildlink3.mk"

.if ${OPSYS} == "Linux"
DEPENDS+=	gst-plugins1-alsa-[0-9]*:../../audio/gst-plugins1-alsa
.else
.  if ${OSS_TYPE} != "none"
DEPENDS+=	gst-plugins1-oss-[0-9]*:../../audio/gst-plugins1-oss
.  endif
.endif

USE_TOOLS+=	msgfmt

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

PYTHON_VERSIONS_ACCEPTED=	312 311

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/* ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1 || ${TRUE}

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
