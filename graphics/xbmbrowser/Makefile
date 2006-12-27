# $NetBSD: Makefile,v 1.27 2006/12/27 13:37:38 joerg Exp $

DISTNAME=		xbmbrowser5.1
PKGNAME=		xbmbrowser-5.1
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		View complete directories of X bitmaps and X pixmaps

USE_TOOLS+=		gmake
USE_IMAKE=		YES

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
