# $NetBSD: Makefile,v 1.63 2004/11/29 19:56:16 wiz Exp $

DISTNAME=	gd-2.0.33
CATEGORIES=	graphics
MASTER_SITES=	http://www.boutell.com/gd/http/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.boutell.com/gd/
COMMENT=	Graphics library for the dynamic creation of images

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
REPLACE_PERL=		bdftogd
PTHREAD_AUTO_VARS=	yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
