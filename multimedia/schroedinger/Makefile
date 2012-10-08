# $NetBSD: Makefile,v 1.2 2012/10/08 09:21:12 asau Exp $
#

DISTNAME=	schroedinger-1.0.11
CATEGORIES=	multimedia
MASTER_SITES=	http://diracvideo.org/download/schroedinger/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://diracvideo.org/
COMMENT=	Dirac video compression library
#LICENSE=	mpl or lgpl or gpl or mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	schroedinger.pc.in

.include "../../devel/orc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
