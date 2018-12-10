# $NetBSD: Makefile,v 1.2 2018/12/10 23:02:41 wiz Exp $

DISTNAME=	shine-3.1.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=savonet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/savonet/shine/
COMMENT=	Fast fixed-point mp3 encoding
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	shine.pc.in

.include "../../mk/bsd.pkg.mk"
