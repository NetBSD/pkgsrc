# $NetBSD: Makefile,v 1.25 2014/08/22 11:24:26 wiz Exp $

DISTNAME=	analitza-${_KDE_VERSION}
PKGREVISION=	4
CATEGORIES=	math
COMMENT=	KDE library for mathematical features

.include "../../meta-pkgs/kde4/Makefile.kde4"

BROKEN_READLINE_DETECTION=	yes

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/readline/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
