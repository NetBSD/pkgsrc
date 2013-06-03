# $NetBSD: Makefile,v 1.27 2013/06/03 10:04:47 wiz Exp $
#

DISTNAME=	libmatchbox-1.9
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://matchbox-project.org/sources/libmatchbox/1.9/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://matchbox-project.org/
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
