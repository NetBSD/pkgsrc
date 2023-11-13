# $NetBSD: Makefile,v 1.11 2023/11/13 15:26:09 wiz Exp $

DISTNAME=	libmaxminddb-1.8.0
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=maxmind/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://maxmind.github.io/libmaxminddb/
COMMENT=	C library for the MaxMind DB file format
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

USE_CC_FEATURES=	c99

PKGCONFIG_OVERRIDE+=	src/libmaxminddb.pc.in

.include "../../mk/bsd.pkg.mk"
