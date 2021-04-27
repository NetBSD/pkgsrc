# $NetBSD: Makefile,v 1.32.10.1 2021/04/27 14:35:55 bsiegert Exp $

DISTNAME=	GeoIP-1.6.12
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=maxmind/}
GITHUB_PROJECT=	geoip-api-c
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/maxmind/geoip-api-c
COMMENT=	GeoIP Legacy C API
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

TEST_TARGET=	check

CONFIGURE_ARGS.NetBSD+=	ac_cv_func_gethostbyname_r=no

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
