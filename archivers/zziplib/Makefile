# $NetBSD: Makefile,v 1.18 2012/09/11 19:47:03 asau Exp $

DISTNAME=	zziplib-0.13.59
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=zziplib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://zziplib.sourceforge.net/
COMMENT=	Library for ZIP archive handling

LICENSE=	gnu-lgpl-v2 OR mpl-1.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../mk/bsd.prefs.mk"

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--disable-builddir

BUILD_DIRS=	zzip zzipwrap bins

TEST_TARGET=		check

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
