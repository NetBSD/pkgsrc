# $NetBSD: Makefile,v 1.3 2012/12/11 10:26:56 ryoon Exp $
#

DISTNAME=	opus-1.0.2
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
