# $NetBSD: Makefile,v 1.14 2012/10/06 14:11:01 asau Exp $

DISTNAME=		jpegpixi-1.1.1
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		http://www.zero-based.org/software/jpegpixi/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.zero-based.org/software/jpegpixi/
COMMENT=		Low-loss JPEG interpolator to remove bad pixels

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

LIBS.SunOS+=		-lintl

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
