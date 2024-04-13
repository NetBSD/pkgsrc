# $NetBSD: Makefile,v 1.19 2024/04/13 05:31:29 adam Exp $

DISTNAME=	opus-1.5.2
PKGNAME=	lib${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	https://downloads.xiph.org/releases/opus/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://opus-codec.org/
COMMENT=	Totally open, royalty-free, highly versatile audio codec library
LICENSE=	modified-bsd

SUPERSEDES=	opus<=1.0.2

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
TEST_TARGET=	check

PKGCONFIG_OVERRIDE+=	opus.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
