# $NetBSD: Makefile,v 1.39 2003/07/17 21:40:41 grant Exp $
#

DISTNAME=       gd-2.0.15
CATEGORIES=	graphics
MASTER_SITES=   http://www.boutell.com/gd/http/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.boutell.com/gd/
COMMENT=	graphics library for fast PNG creation

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
REPLACE_PERL=		bdftogd

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
