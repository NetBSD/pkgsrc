# $NetBSD: Makefile,v 1.9 2005/07/21 16:29:48 wiz Exp $
#

DISTNAME=	libmatchbox-1.6
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://projects.o-hand.com/matchbox/sources/libmatchbox/1.6/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://projects.o-hand.com/matchbox/
COMMENT=	Library for matchbox window manager for computers with small displays

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
