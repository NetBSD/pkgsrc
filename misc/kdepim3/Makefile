# $NetBSD: Makefile,v 1.19 2004/01/03 18:49:47 reed Exp $

DISTNAME=	kdepim-3.1.4
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	Personal Information Management tools for the KDE desktop
PKGREVISION=	1

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES
LIBTOOL_OVERRIDE+=	${WRKSRC}/libical/libtool

.include "../../comms/pilot-link-libs/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
