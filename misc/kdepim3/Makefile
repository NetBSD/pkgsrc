# $NetBSD: Makefile,v 1.15 2003/07/30 14:19:38 markd Exp $

DISTNAME=	kdepim-3.1.3
CATEGORIES=	misc
COMMENT=	Personal Information Management tools for the KDE desktop

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES
LIBTOOL_OVERRIDE+=	${WRKSRC}/libical/libtool

.include "../../comms/pilot-link-libs/buildlink2.mk"
.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
