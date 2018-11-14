# $NetBSD: Makefile,v 1.37 2018/11/14 22:22:01 kleink Exp $

DISTNAME=	gaupol-0.28.2
PKGREVISION=	9
CATEGORIES=	misc
#MASTER_SITES=	http://download.gna.org/gaupol/0.28/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://otsaloma.io/gaupol/
COMMENT=	Subtitle editor
LICENSE=	gnu-gpl-v3

DEPENDS+=	iso-codes-[0-9]*:../../textproc/iso-codes
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-enchant>=1.4:../../textproc/py-enchant
DEPENDS+=	${PYPKGPREFIX}-gobject3>=3.6.0:../../devel/py-gobject3
DEPENDS+=	gstreamer1>=1.0:../../multimedia/gstreamer1
DEPENDS+=	gst-plugins1-bad-[0-9]*:../../multimedia/gst-plugins1-bad
DEPENDS+=	gst-plugins1-pango-[0-9]*:../../devel/gst-plugins1-pango
DEPENDS+=	gst-plugins1-base-[0-9]*:../../multimedia/gst-plugins1-base
DEPENDS+=	gst-plugins1-good-[0-9]*:../../multimedia/gst-plugins1-good
DEPENDS+=	gst-plugins1-libav-[0-9]*:../../multimedia/gst-plugins1-libav
DEPENDS+=	gst-plugins1-ugly-[0-9]*:../../multimedia/gst-plugins1-ugly
DEPENDS+=	gst-plugins1-x11-[0-9]*:../../x11/gst-plugins1-x11
DEPENDS+=	paratype-ttf-[0-9]*:../../fonts/paratype-ttf
# suggests installing either mplayer or vlc for preview
# but that's not necessary with gst* installed

USE_LANGUAGES=			# none
USE_TOOLS+=			intltool msgfmt

PYSETUPARGS=			--mandir=${PREFIX}/${PKGMANDIR}
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/distutils.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
