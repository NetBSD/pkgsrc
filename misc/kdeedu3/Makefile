# $NetBSD: Makefile,v 1.67 2012/09/15 10:05:39 obache Exp $

DISTNAME=	kdeedu-${_KDE_VERSION}
PKGREVISION=	17
CATEGORIES=	misc
COMMENT=	Edu{tainment,cation} tools for the KDE integrated X11 desktop

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/kde3/Makefile.kde3"

REPLACE_PERL+=	\
	kvoctrain/kvoctrain/langen2kvtml \
	kvoctrain/kvoctrain/spotlight2kvtml

REPLACE_PYTHON+=	kig/pykig/pykig.py

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
