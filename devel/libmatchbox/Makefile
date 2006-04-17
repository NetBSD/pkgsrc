# $NetBSD: Makefile,v 1.15 2006/04/17 13:46:01 wiz Exp $
#

DISTNAME=	libmatchbox-1.7
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://projects.o-hand.com/matchbox/sources/libmatchbox/1.7/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://projects.o-hand.com/matchbox/
COMMENT=	Library for matchbox window manager for computers with small displays

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
