# $NetBSD: Makefile,v 1.15 2017/04/30 01:21:34 ryoon Exp $

DISTNAME=	poxml-${_KDE_VERSION}
PKGREVISION=	6
CATEGORIES=	devel
COMMENT=	Translates DocBook XML files using gettext po files

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
