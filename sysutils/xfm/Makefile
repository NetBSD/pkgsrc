# $NetBSD: Makefile,v 1.6 2004/04/18 23:47:03 snj Exp $
# FreeBSD Id: ports/x11-fm/xfm/Makefile,v 1.20 2001/02/05 21:00:55 olgeni Exp

DISTNAME=	xfm-1.4.3
PKGREVISION=	1
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.musikwissenschaft.uni-mainz.de/~ag/xfm/

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://www.musikwissenschaft.uni-mainz.de/~ag/xfm/
COMMENT=	The X File Manager

WRKSRC=		${WRKDIR}/xfm-1.4.3
USE_BUILDLINK3=	YES
USE_IMAKE=	YES

.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/Xaw3d/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
