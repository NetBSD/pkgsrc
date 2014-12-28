# $NetBSD: Makefile,v 1.30 2014/12/28 15:17:47 mef Exp $
#

DISTNAME=	libmatchbox-1.9
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	http://downloads.yoctoproject.org/releases/matchbox/libmatchbox/1.9/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.yoctoproject.org/tools-resources/projects/matchbox/
COMMENT=	Library for matchbox window manager for computers with small displays

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
