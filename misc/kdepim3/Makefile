# $NetBSD: Makefile,v 1.2 2002/07/17 07:54:11 skrll Exp $

DISTNAME=	kdepim-3.0.2
CATEGORIES=	misc
COMMENT=	Personal Information Management tools for the KDE desktop

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK_ONLY=	YES
LIBTOOL_OVERRIDE+=	${WRKSRC}/libical/libtool

.include "../../comms/pilot-link-libs/buildlink.mk"
.include "../../x11/kde3/buildlink.mk"
.include "../../x11/kdebase3/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
