# $NetBSD: Makefile,v 1.13 2026/06/24 06:27:17 drixter Exp $

DISTNAME=	di-6.2.2.2
CATEGORIES=	sysutils
MASTER_SITES=	https://sourceforge.net/projects/diskinfo-di/files/

MAINTAINER=	brad.lanam.di@gmail.com
HOMEPAGE=	https://diskinfo-di.sourceforge.io/
COMMENT=	Alternative df command
LICENSE=	zlib

USE_LANGUAGES=		c
USE_TOOLS+=		msgfmt pkg-config sed tr grep sh
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE=	di.pc.in

.include "../../devel/cmake/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
