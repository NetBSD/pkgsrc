# $NetBSD: Makefile,v 1.19 2004/04/24 01:18:26 wiz Exp $
# FreeBSD: Makefile,v 1.3 1997/08/26 07:12:20 tg Exp
#

DISTNAME=		xbmbrowser5.1
PKGNAME=		xbmbrowser-5.1
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_XCONTRIB:=utilities/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		View complete directories of X bitmaps and X pixmaps

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_IMAKE=		YES

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
