# $NetBSD: Makefile,v 1.9 2003/03/11 13:22:25 markd Exp $

DISTNAME=	kdepim-3.1
CATEGORIES=	misc
COMMENT=	Personal Information Management tools for the KDE desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES
LIBTOOL_OVERRIDE+=	${WRKSRC}/libical/libtool

.include "../../comms/pilot-link-libs/buildlink2.mk"
.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
