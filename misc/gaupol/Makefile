# $NetBSD: Makefile,v 1.58 2023/11/12 13:22:44 wiz Exp $

DISTNAME=	gaupol-1.11
PKGREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=otsaloma/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://otsaloma.io/gaupol/
COMMENT=	Subtitle editor
LICENSE=	gnu-gpl-v3

DEPENDS+=	iso-codes>=3.67:../../textproc/iso-codes
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-gobject3>=3.12.0:../../devel/py-gobject3
DEPENDS+=	gstreamer1>=1.6:../../multimedia/gstreamer1
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
USE_TOOLS+=			msgfmt

PYSETUPARGS=			--mandir=${PREFIX}/${PKGMANDIR}
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gspell/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk3+=	gtk3+>=3.12.0
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
