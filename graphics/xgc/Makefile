# $NetBSD: Makefile,v 1.3 2013/06/09 12:12:26 rodent Exp $
#

DISTNAME=	xgc-1.0.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Graphics demo showing the X11 core protocol graphics primitives
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	bison flex pkg-config

MAKE_FLAGS+=	appdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
