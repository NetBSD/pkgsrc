# $NetBSD: Makefile,v 1.14 2020/01/26 17:30:43 rillig Exp $

DISTNAME=	opus-1.3.1
PKGNAME=	lib${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	https://archive.mozilla.org/pub/opus/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://opus-codec.org/
COMMENT=	Totally open, royalty-free, highly versatile audio codec library
LICENSE=	modified-bsd

SUPERSEDES=	opus<=1.0.2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--enable-ambisonics

PKGCONFIG_OVERRIDE+=	opus.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
