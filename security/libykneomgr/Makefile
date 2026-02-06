# $NetBSD: Makefile,v 1.29 2026/02/06 10:05:48 wiz Exp $

DISTNAME=	libykneomgr-0.1.8
PKGREVISION=	16
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/libykneomgr/Releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/libykneomgr/
COMMENT=	Yubikey NEO C library and command-line tool
LICENSE=	gnu-lgpl-v3

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	pkg-config

TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
