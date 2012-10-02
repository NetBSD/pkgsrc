# $NetBSD: Makefile,v 1.2 2012/10/02 23:47:56 asau Exp $
#

DISTNAME=	opus-1.0.1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/opus/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://opus-codec.org/
COMMENT=	Totally open, royalty-free, highly versatile audio codec library
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	opus.pc.in

.include "../../mk/bsd.pkg.mk"
