# $NetBSD: Makefile,v 1.4 2002/09/10 16:06:46 wiz Exp $

DISTNAME=	kdepim-3.0.3
PKGREVISION=	1
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
