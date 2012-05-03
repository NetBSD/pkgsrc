# $NetBSD: Makefile,v 1.30 2012/05/03 09:55:30 obache Exp $

DISTNAME=		xbmbrowser5.1
PKGNAME=		xbmbrowser-5.1
PKGREVISION=		5
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		View complete directories of X bitmaps and X pixmaps

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
USE_IMAKE=		YES

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
