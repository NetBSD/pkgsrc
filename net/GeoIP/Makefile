# $NetBSD: Makefile,v 1.31 2016/10/19 11:59:25 fhajny Exp $

DISTNAME=	GeoIP-1.6.9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=maxmind/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.maxmind.com/app/c
COMMENT=	GeoIP Legacy C API
LICENSE=	gnu-lgpl-v2.1

GITHUB_PROJECT=	geoip-api-c
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

TEST_TARGET=	check

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
