# $NetBSD: Makefile,v 1.22 2004/03/08 19:40:41 jmmv Exp $

DISTNAME=	kdeedu-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	Edu{tainment,cation} tools for the KDE integrated X11 desktop

DEPENDS+=	xdg-dirs>=1.1:../../misc/xdg-dirs

.include "../../meta-pkgs/kde3/Makefile.kde3"

REPLACE_PERL=	\
	kvoctrain/kvoctrain/langen2kvtml \
	kvoctrain/kvoctrain/spotlight2kvtml

USE_BUILDLINK2=		YES

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
