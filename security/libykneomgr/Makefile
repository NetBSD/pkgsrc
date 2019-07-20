# $NetBSD: Makefile,v 1.9 2019/07/20 22:46:48 wiz Exp $

DISTNAME=	libykneomgr-0.1.6
PKGREVISION=	6
CATEGORIES=	security
MASTER_SITES=	https://developers.yubico.com/libykneomgr/Releases/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/libykneomgr/
COMMENT=	Yubikey NEO C library and command-line tool

MAKE_JOBS_SAFE=	no

LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS=		pkg-config

BUILD_DEPENDS+=		help2man-[0-9]*:../../converters/help2man

.include "../../security/pcsc-lite/buildlink3.mk"
.include "../../archivers/libzip/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
