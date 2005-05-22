# $NetBSD: Makefile,v 1.19 2005/05/22 20:07:37 jlam Exp $
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

USE_TOOLS+=	gmake
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/cdparanoia

MAKE_ENV+=	GCC=yes

LDFLAGS.FreeBSD+=	-lcam
LDFLAGS.DragonFly+=     -lcam

.include "../../mk/bsd.pkg.mk"
