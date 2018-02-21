# $NetBSD: Makefile,v 1.23 2018/02/21 10:43:45 ryoon Exp $

DISTNAME=	zziplib-0.13.68
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GITHUB:=gdraheim/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gdraheim/zziplib
COMMENT=	Library for ZIP archive handling
LICENSE=	gnu-lgpl-v2 OR mpl-1.1

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--disable-builddir

BUILD_DIRS=		zzip zzipwrap bins

TEST_TARGET=		check

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
