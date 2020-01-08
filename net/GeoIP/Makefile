# $NetBSD: Makefile,v 1.32 2020/01/08 11:59:43 nia Exp $

DISTNAME=	GeoIP-1.6.12
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

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
