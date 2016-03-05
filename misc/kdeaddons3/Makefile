# $NetBSD: Makefile,v 1.103 2016/03/05 11:28:55 jperkin Exp $

DISTNAME=	kdeaddons-${_KDE_VERSION}
PKGREVISION=	43
CATEGORIES=	misc
COMMENT=	Add ons for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

REPLACE_PERL+=	knewsticker-scripts/bbc.pl \
		knewsticker-scripts/newsrss.pl \
		knewsticker-scripts/stock.pl \
		konq-plugins/mediarealfolder/kio_media_realfolder

REPLACE_PYTHON+= \
		knewsticker-scripts/fyensget.py \
		knewsticker-scripts/sportscores.py \
		konq-plugins/imagerotation/exif.py \
		konq-plugins/imagerotation/orient.py

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../lang/python/application.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../games/kdegames3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../misc/kdepim3/buildlink3.mk"
.include "../../multimedia/kdemultimedia3/buildlink3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
