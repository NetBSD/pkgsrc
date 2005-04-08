# $NetBSD: Makefile,v 1.5 2005/04/08 14:09:58 ben Exp $
#

DISTNAME=	libmatchbox-1.6
CATEGORIES=	devel
MASTER_SITES=	http://projects.o-hand.com/matchbox/sources/libmatchbox/1.6/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://projects.o-hand.com/matchbox/
COMMENT=	Library for matchbox window manager for computers with small displays

USE_BUILDLINK3=	yes
USE_X11=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
