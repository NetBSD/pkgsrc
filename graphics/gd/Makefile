# $NetBSD: Makefile,v 1.66.2.1 2006/06/15 12:56:54 ghen Exp $

DISTNAME=	gd-2.0.33
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.boutell.com/gd/http/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.boutell.com/gd/
COMMENT=	Graphics library for the dynamic creation of images

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		YES
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		YES
REPLACE_PERL+=		bdftogd
PTHREAD_AUTO_VARS=	yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
