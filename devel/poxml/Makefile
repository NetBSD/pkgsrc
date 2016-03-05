# $NetBSD: Makefile,v 1.12 2016/03/05 11:28:25 jperkin Exp $

DISTNAME=	poxml-${_KDE_VERSION}
PKGREVISION=	3
CATEGORIES=	devel
COMMENT=	Translates DocBook XML files using gettext po files

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
