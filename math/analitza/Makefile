# $NetBSD: Makefile,v 1.3 2012/06/16 04:45:31 markd Exp $

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
