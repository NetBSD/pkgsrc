# $NetBSD: Makefile,v 1.1.1.1 2004/09/30 11:25:58 agc Exp $
#

DISTNAME=	libmatchbox-1.4
CATEGORIES=	devel
MASTER_SITES=	http://matchbox.handhelds.org/sources/libmatchbox/1.4/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://matchbox.handhelds.org/
COMMENT=	Library for matchbox window manager for computers with small displays

USE_BUILDLINK3=	yes
USE_X11=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
