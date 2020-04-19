# $NetBSD: Makefile,v 1.32 2020/04/19 12:18:22 rillig Exp $
#

DISTNAME=	libmatchbox-1.9
PKGREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	http://downloads.yoctoproject.org/releases/matchbox/libmatchbox/1.9/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.yoctoproject.org/tools-resources/projects/matchbox/
COMMENT=	Library for matchbox window manager for computers with small displays
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
