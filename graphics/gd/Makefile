# $NetBSD: Makefile,v 1.38 2003/06/23 09:53:10 adam Exp $
#

DISTNAME=       gd-2.0.15
CATEGORIES=	graphics
MASTER_SITES=   http://www.boutell.com/gd/http/

MAINTAINER=	adam@netbsd.org
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
