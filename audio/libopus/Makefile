# $NetBSD: Makefile,v 1.11 2017/05/29 12:10:01 wiz Exp $

DISTNAME=	opus-1.1.5
PKGNAME=	lib${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/opus/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://opus-codec.org/
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
