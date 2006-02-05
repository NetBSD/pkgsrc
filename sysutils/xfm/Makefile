# $NetBSD: Makefile,v 1.12 2006/02/05 23:10:58 joerg Exp $

DISTNAME=	xfm-1.4.3
PKGREVISION=	2
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.musikwissenschaft.uni-mainz.de/~ag/xfm/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.musikwissenschaft.uni-mainz.de/~ag/xfm/
COMMENT=	The X File Manager

BROKEN_IN=	pkgsrc-2005Q4

WRKSRC=		${WRKDIR}/xfm-1.4.3
USE_IMAKE=	YES

.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/Xaw3d/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
