# $NetBSD: Makefile,v 1.5 2002/10/03 12:08:46 markd Exp $

DISTNAME=	kdepim-3.0.3
PKGREVISION=	1
CATEGORIES=	misc
COMMENT=	Personal Information Management tools for the KDE desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES
LIBTOOL_OVERRIDE+=	${WRKSRC}/libical/libtool

.include "../../comms/pilot-link-libs/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
