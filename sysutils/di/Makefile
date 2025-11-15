# $NetBSD: Makefile,v 1.12 2025/11/15 20:11:48 bsiegert Exp $

DISTNAME=	di-6.2.0
CATEGORIES=	sysutils
MASTER_SITES=	https://sourceforge.net/projects/diskinfo-di/files/

MAINTAINER=	brad.lanam.di@gmail.com
HOMEPAGE=	https://diskinfo-di.sourceforge.io/
COMMENT=	Alternative df command
LICENSE=	zlib

USE_LANGUAGES=		c
USE_TOOLS+=		msgfmt pkg-config sed tr grep sh
USE_PKGLOCALEDIR=	yes

.include "../../devel/cmake/build.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
