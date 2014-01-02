# $NetBSD: Makefile,v 1.4 2014/01/02 14:43:21 ryoon Exp $
#

DISTNAME=	opus-1.1
PKGNAME=	lib${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/opus/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://opus-codec.org/
COMMENT=	Totally open, royalty-free, highly versatile audio codec library
LICENSE=	modified-bsd

CONFLICTS=	opus<=1.0.2
SUPERSEDES=	opus<=1.0.2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	opus.pc.in

.include "../../mk/bsd.pkg.mk"
