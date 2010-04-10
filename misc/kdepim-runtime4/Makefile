# $NetBSD: Makefile,v 1.6 2010/04/10 02:45:03 markd Exp $

DISTNAME=	kdepim-runtime-${_KDE_VERSION}
CATEGORIES=	misc
COMMENT=	Runtime requirements for the KDE PIM tools

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
