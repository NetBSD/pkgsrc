# $NetBSD: Makefile,v 1.1.1.1 2004/11/29 14:16:57 wiz Exp $

DISTNAME=		jpegpixi-1.0.3
CATEGORIES=		graphics
MASTER_SITES=		http://www.zero-based.org/software/jpegpixi/

MAINTAINER=		gdt@ir.bbn.com
HOMEPAGE=		http://www.zero-based.org/software/jpegpixi/
COMMENT=		Low-loss JPEG interpolator to remove bad pixels

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
