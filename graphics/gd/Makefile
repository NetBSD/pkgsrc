# $NetBSD: Makefile,v 1.44 2004/01/06 08:00:28 jlam Exp $
#

DISTNAME=       gd-2.0.17
CATEGORIES=	graphics
MASTER_SITES=   http://www.boutell.com/gd/http/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.boutell.com/gd/
COMMENT=	Graphics library for the dynamic creation of images

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
REPLACE_PERL=		bdftogd
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
LIBS+=			-lpthread

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
