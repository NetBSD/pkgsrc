# $NetBSD: Makefile,v 1.4 2014/02/12 23:17:49 tron Exp $

DISTNAME=	poxml-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	devel
COMMENT=	Translates DocBook XML files using gettext po files

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
