# $NetBSD: Makefile,v 1.17 2006/12/15 20:32:54 joerg Exp $
#

DISTNAME=	libmatchbox-1.9
CATEGORIES=	devel
MASTER_SITES=	http://projects.o-hand.com/matchbox/sources/libmatchbox/1.9/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.o-hand.com/matchbox/
COMMENT=	Library for matchbox window manager for computers with small displays

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
