# $NetBSD: Makefile,v 1.67 2019/10/01 19:37:50 nia Exp $

DISTNAME=	exaile-4.0.0
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
