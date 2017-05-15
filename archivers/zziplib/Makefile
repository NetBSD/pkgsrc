# $NetBSD: Makefile,v 1.20 2017/05/15 08:40:21 spz Exp $

PKGNAME=        zziplib-${VERSION}
DISTNAME=	${PKGNAME}
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_GITHUB:=gdraheim/}
GITHUB_PROJECT= zziplib
GITHUB_TAG=	v${VERSION}
EXTRACT_SUFX=	.tar.gz
VERSION=	0.13.66


MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gdraheim/zziplib
COMMENT=	Library for ZIP archive handling

LICENSE=	gnu-lgpl-v2 OR mpl-1.1

.include "../../mk/bsd.prefs.mk"

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
CONFIGURE_ARGS+=	--disable-builddir

BUILD_DIRS=	zzip zzipwrap bins

TEST_TARGET=		check

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
