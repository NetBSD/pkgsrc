# $NetBSD: Makefile,v 1.3 2010/01/17 12:02:28 wiz Exp $

DISTNAME=	kdepim-runtime-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	Runtime requirements for the KDE PIM tools

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../misc/kdepimlibs4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/kdelibs-experimental4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
