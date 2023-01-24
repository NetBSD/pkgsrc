# $NetBSD: Makefile,v 1.6 2023/01/24 18:36:33 wiz Exp $

DISTNAME=	minisign-0.10
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
