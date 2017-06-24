# $NetBSD: Makefile,v 1.9 2017/06/24 18:57:28 agc Exp $

DISTNAME=	snappy-1.1.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://google.github.io/snappy/
COMMENT=	General purpose data compression library
LICENSE=	apache-2.0

GITHUB_RELEASE=	${PKGVERSION_NOREV}

USE_LANGUAGES+=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	snappy.pc.in

.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
