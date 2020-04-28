# $NetBSD: Makefile,v 1.70 2020/04/28 12:52:02 nia Exp $

DISTNAME=	exaile-4.0.2
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=exaile/}
GITHUB_PROJECT=	exaile
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.exaile.org/
COMMENT=	Music Player for GTK+
LICENSE=	gnu-gpl-v2 # or later

USE_TOOLS+=	pkg-config gmake
USE_TOOLS+=	msgfmt msgmerge xgettext

MAKE_FLAGS+=	PYTHON2_CMD=${PYTHONBIN}

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-gstreamer1-[0-9]*:../../multimedia/py-gstreamer1
DEPENDS+=	${PYPKGPREFIX}-mutagen-[0-9]*:../../audio/py-mutagen

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

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

EGDIR=		${PREFIX}/share/examples/xdg/exaile

OWN_DIRS+=	${PKG_SYSCONFDIR}/xdg/exaile
CONF_FILES+=	${EGDIR}/settings.ini ${PKG_SYSCONFDIR}/xdg/exaile/settings.ini

# https://github.com/exaile/exaile/issues/246
PYTHON_VERSIONS_ACCEPTED=	27

.include "../../lang/python/application.mk"

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-configure
SUBST_MESSAGE.py=	Set path to python interpreter.
SUBST_FILES.py+=	exaile
SUBST_VARS.py+=		PYTHONBIN

.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../textproc/py-elementtree/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
