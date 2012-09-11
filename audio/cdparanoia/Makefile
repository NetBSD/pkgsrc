# $NetBSD: Makefile,v 1.32 2012/09/11 23:59:28 asau Exp $
#

DISTNAME=	cdparanoia-III-10.2
PKGNAME=	cdparanoia-3.0.10.2
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://downloads.xiph.org/releases/cdparanoia/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.xiph.org/paranoia/
COMMENT=	CDDA reading utility with extra data verification features
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-*-* Linux-*-* DragonFly-*-* Darwin-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gmake
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/cdparanoia

MAKE_ENV+=	GCC=yes
CFLAGS+=	-Dprivate_data=private

LDFLAGS.FreeBSD+=	-lcam
LDFLAGS.DragonFly+=	-lcam

.include "../../mk/bsd.pkg.mk"
