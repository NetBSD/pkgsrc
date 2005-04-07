# $NetBSD: Makefile,v 1.4 2005/04/07 13:43:15 ben Exp $
#

DISTNAME=	libmatchbox-1.6
CATEGORIES=	devel
MASTER_SITES=	http://matchbox.handhelds.org/sources/libmatchbox/1.6/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://matchbox.handhelds.org/
COMMENT=	Library for matchbox window manager for computers with small displays

USE_BUILDLINK3=	yes
USE_X11=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
