# $NetBSD: Makefile,v 1.1 2014/11/14 13:35:09 pettai Exp $

DISTNAME=	libykneomgr-0.1.6
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/libykneomgr/Releases/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/libykneomgr/
COMMENT=	Yubikey NEO library

LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS=		pkg-config

.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
