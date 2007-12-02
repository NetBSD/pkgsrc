# $NetBSD: Makefile,v 1.15 2007/12/02 11:41:48 wiz Exp $
#

DISTNAME=	xdu-3.0
PKGREVISION=	6
CATEGORIES=	sysutils x11
MASTER_SITES=	http://sd.wareonearth.com/~phil/xdu/
PATCH_SITES=	http://www.nn.iij4u.or.jp/~tutimura/xdu/
EXTRACT_SUFX=	.tar.Z
PATCHFILES+=	xdu-3.0.dirname.patch \
		xdu-3.0.i18n.patch

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://sd.wareonearth.com/~phil/xdu/
COMMENT=	Display the output of "du" in an X window

WRKSRC=		${WRKDIR}
USE_IMAKE=	yes

PATCH_DIST_STRIP.xdu-3.0.dirname.patch	= -p1
PATCH_DIST_STRIP.xdu-3.0.i18n.patch	= -p1

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
