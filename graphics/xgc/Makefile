# $NetBSD: Makefile,v 1.7 2022/10/15 23:12:35 wiz Exp $

DISTNAME=	xgc-1.0.6
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
