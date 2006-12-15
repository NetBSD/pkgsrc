# $NetBSD: Makefile,v 1.14 2006/12/15 20:33:01 joerg Exp $

DISTNAME=	xfm-1.4.3
PKGREVISION=	2
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.musikwissenschaft.uni-mainz.de/~ag/xfm/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://www.musikwissenschaft.uni-mainz.de/~ag/xfm/
COMMENT=	The X File Manager

BUILD_TARGET+=	all xfm.install.script Xfm.ad

WRKSRC=		${WRKDIR}/xfm-1.4.3
USE_IMAKE=	YES

.include "../../x11/Xaw3d/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
