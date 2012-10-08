# $NetBSD: Makefile,v 1.68 2012/10/08 09:57:26 asau Exp $

DISTNAME=	kdeedu-${_KDE_VERSION}
PKGREVISION=	17
CATEGORIES=	misc
COMMENT=	Edu{tainment,cation} tools for the KDE integrated X11 desktop

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
