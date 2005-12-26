# $NetBSD: Makefile,v 1.9 2005/12/26 23:39:34 schmonz Exp $

DISTNAME=	xfm-1.4.3
PKGREVISION=	1
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.musikwissenschaft.uni-mainz.de/~ag/xfm/

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://www.musikwissenschaft.uni-mainz.de/~ag/xfm/
COMMENT=	The X File Manager

PKG_FAIL_REASON+=	"Broken on NetBSD/i386 3.0 in pkgsrc-2005Q4"
PKG_FAIL_REASON+=	"Will be removed in pkgsrc-2006Q1 unless fixed"

WRKSRC=		${WRKDIR}/xfm-1.4.3
USE_IMAKE=	YES

.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/Xaw3d/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
