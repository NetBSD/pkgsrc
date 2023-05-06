# $NetBSD: Makefile,v 1.17 2023/05/06 18:51:15 ryoon Exp $

DISTNAME=	opus-1.4
PKGNAME=	lib${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/opus/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://opus-codec.org/
COMMENT=	Totally open, royalty-free, highly versatile audio codec library
LICENSE=	modified-bsd

SUPERSEDES=	opus<=1.0.2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	opus.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
