# $NetBSD: Makefile,v 1.11 2025/03/08 10:19:04 bsiegert Exp $

DISTNAME=	di-5.0.14
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
