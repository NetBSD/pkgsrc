# $NetBSD: Makefile,v 1.1 2015/01/03 00:39:26 wiz Exp $

DISTNAME=	shine-3.1.0
CATEGORIES=	audio
MASTER_SITES=	https://github.com/savonet/shine/releases/download/3.1.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/savonet/shine/
COMMENT=	Fast fixed-point mp3 encoding
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	shine.pc.in

.include "../../mk/bsd.pkg.mk"
