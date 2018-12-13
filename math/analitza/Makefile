# $NetBSD: Makefile,v 1.42 2018/12/13 19:51:35 adam Exp $

DISTNAME=	analitza-${_KDE_VERSION}
PKGREVISION=	15
CATEGORIES=	math
COMMENT=	KDE library for mathematical features

.include "../../meta-pkgs/kde4/Makefile.kde4"

BROKEN_READLINE_DETECTION=	yes

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
