# $NetBSD: Makefile,v 1.54 2004/06/20 21:46:36 xtraeme Exp $

DISTNAME=	gd-2.0.25
PKGREVISION=	1
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
LIBS+=			${PTHREAD_LDFLAGS}

BUILDLINK_DEPENDS.freetype2=	freetype2>=2.1.4

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
