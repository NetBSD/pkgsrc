# $NetBSD: Makefile,v 1.2 2004/03/26 02:27:46 wiz Exp $

DISTNAME=	kdeaccessibility-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	Accessibility support for the KDE integrated X11 desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

.include "../../mk/bsd.prefs.mk"

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
