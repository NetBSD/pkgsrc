# $NetBSD: Makefile,v 1.16.4.1 2005/03/31 14:54:26 salo Exp $
#

DISTNAME=	cdparanoia-III-alpha9.8
PKGNAME=	cdparanoia-3.0.9.8
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.xiph.org/paranoia/download/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.xiph.org/paranoia/
COMMENT=	CDDA reading utility with extra data verification features

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-*-* Linux-*-* DragonFly-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/cdparanoia

MAKE_ENV+=	GCC=yes

LDFLAGS.FreeBSD+=	-lcam
LDFLAGS.DragonFly+=     -lcam

.include "../../mk/bsd.pkg.mk"
