# $NetBSD: Makefile,v 1.27 2009/05/19 00:36:06 dholland Exp $
#

DISTNAME=	cdparanoia-III-alpha9.8
PKGNAME=	cdparanoia-3.0.9.8
PKGREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://www.xiph.org/paranoia/download/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.xiph.org/paranoia/
COMMENT=	CDDA reading utility with extra data verification features

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-*-* Linux-*-* DragonFly-*-* Darwin-*-*

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/cdparanoia

MAKE_ENV+=	GCC=yes

LDFLAGS.FreeBSD+=	-lcam
LDFLAGS.DragonFly+=	-lcam

.include "../../mk/bsd.pkg.mk"
