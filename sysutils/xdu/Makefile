# $NetBSD: Makefile,v 1.18 2012/05/03 09:55:31 obache Exp $
#

DISTNAME=	xdu-3.0
PKGREVISION=	8
CATEGORIES=	sysutils x11
MASTER_SITES=	http://sd.wareonearth.com/~phil/xdu/
PATCH_SITES=	http://www.nn.iij4u.or.jp/~tutimura/xdu/
EXTRACT_SUFX=	.tar.Z
PATCHFILES+=	xdu-3.0.dirname.patch \
		xdu-3.0.i18n.patch

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://sd.wareonearth.com/~phil/xdu/
COMMENT=	Display the output of "du" in an X window

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_IMAKE=	yes

PATCH_DIST_STRIP.xdu-3.0.dirname.patch	= -p1
PATCH_DIST_STRIP.xdu-3.0.i18n.patch	= -p1

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
