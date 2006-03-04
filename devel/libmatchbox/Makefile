# $NetBSD: Makefile,v 1.14 2006/03/04 21:29:17 jlam Exp $
#

DISTNAME=	libmatchbox-1.7
PKGREVISION=	2
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
