# $NetBSD: Makefile,v 1.5 2004/04/27 11:06:56 adam Exp $
#

DISTNAME=	libpixman-0.1.1
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://cairographics.org/
COMMENT=	Pixel manipulation library

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libpixman.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
