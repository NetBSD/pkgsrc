# $NetBSD: Makefile,v 1.2 2004/02/14 17:21:42 jlam Exp $
#

DISTNAME=	libpixman-0.1.0
CATEGORIES=	graphics
MASTER_SITES=	http://cairographics.org/snapshots/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://cairographics.org/
COMMENT=	Pixel manipulation library

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libpixman.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
