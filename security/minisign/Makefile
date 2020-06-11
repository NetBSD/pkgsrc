# $NetBSD: Makefile,v 1.3 2020/06/11 11:10:22 fcambus Exp $

DISTNAME=	minisign-0.9
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=jedisct1/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/jedisct1/minisign/
COMMENT=	Dead simple tool to sign files and verify signatures
LICENSE=	isc

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
