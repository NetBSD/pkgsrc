# $NetBSD: Makefile,v 1.5 2014/01/05 19:56:50 wiz Exp $

DISTNAME=	opus-1.1
PKGNAME=	lib${DISTNAME}
PKGREVISION=	1
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
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	opus.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
