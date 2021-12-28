# $NetBSD: Makefile,v 1.5 2021/12/28 12:04:09 adam Exp $

DISTNAME=	nanomsg-1.1.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=nanomsg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://nanomsg.org/
COMMENT=	Scalability protocols library
LICENSE=	x11

USE_CMAKE=	yes
TEST_TARGET=	test
# For Darwin
TEST_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}

PKGCONFIG_OVERRIDE+=	src/pkgconfig.in

.include "../../mk/bsd.pkg.mk"
