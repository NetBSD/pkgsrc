# $NetBSD: Makefile,v 1.8 2022/07/25 11:12:24 wiz Exp $

DISTNAME=	libmaxminddb-1.6.0
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=maxmind/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://maxmind.github.io/libmaxminddb/
COMMENT=	C library for the MaxMind DB file format
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c99
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	src/libmaxminddb.pc.in

.include "../../mk/bsd.pkg.mk"
