# $NetBSD: Makefile,v 1.26 2014/11/07 19:39:25 adam Exp $

DISTNAME=	analitza-${_KDE_VERSION}
PKGREVISION=	5
CATEGORIES=	math
COMMENT=	KDE library for mathematical features

.include "../../meta-pkgs/kde4/Makefile.kde4"

BROKEN_READLINE_DETECTION=	yes

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/readline/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
