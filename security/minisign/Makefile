# $NetBSD: Makefile,v 1.7 2023/03/03 07:44:02 fcambus Exp $

DISTNAME=	minisign-0.11
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=jedisct1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jedisct1/minisign/
COMMENT=	Dead simple tool to sign files and verify signatures
LICENSE=	isc

USE_TOOLS+=	pkg-config

.include "../../devel/cmake/build.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
