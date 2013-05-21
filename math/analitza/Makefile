# $NetBSD: Makefile,v 1.13 2013/05/21 12:49:33 markd Exp $

DISTNAME=	analitza-${_KDE_VERSION}
CATEGORIES=	math
COMMENT=	KDE library for mathematical features

.include "../../meta-pkgs/kde4/Makefile.kde4"

USE_GNU_READLINE=	yes
BROKEN_READLINE_DETECTION=	yes

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../devel/readline/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
