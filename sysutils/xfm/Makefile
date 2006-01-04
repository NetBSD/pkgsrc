# $NetBSD: Makefile,v 1.10 2006/01/04 04:29:08 schmonz Exp $

DISTNAME=	xfm-1.4.3
PKGREVISION=	1
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.musikwissenschaft.uni-mainz.de/~ag/xfm/

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://www.musikwissenschaft.uni-mainz.de/~ag/xfm/
COMMENT=	The X File Manager

BROKEN_IN=	pkgsrc-2005Q4

WRKSRC=		${WRKDIR}/xfm-1.4.3
USE_IMAKE=	YES

.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/Xaw3d/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
