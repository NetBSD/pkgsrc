# $NetBSD: Makefile,v 1.9 2005/02/09 21:24:50 xtraeme Exp $
#

DISTNAME=	libpixman-0.1.3
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
