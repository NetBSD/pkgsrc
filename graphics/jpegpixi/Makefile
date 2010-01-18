# $NetBSD: Makefile,v 1.10 2010/01/18 09:59:03 wiz Exp $

DISTNAME=		jpegpixi-1.1.1
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		http://www.zero-based.org/software/jpegpixi/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.zero-based.org/software/jpegpixi/
COMMENT=		Low-loss JPEG interpolator to remove bad pixels

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
