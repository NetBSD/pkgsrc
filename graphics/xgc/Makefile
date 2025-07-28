# $NetBSD: Makefile,v 1.8 2025/07/28 12:12:03 wiz Exp $

DISTNAME=	xgc-1.0.7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Graphics demo showing the X11 core protocol graphics primitives
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_TOOLS+=	bison flex pkg-config

MAKE_FLAGS+=	appdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
