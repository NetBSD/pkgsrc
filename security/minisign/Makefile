# $NetBSD: Makefile,v 1.5 2022/06/27 15:29:17 fcambus Exp $

DISTNAME=	minisign-0.10
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=jedisct1/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jedisct1/minisign/
COMMENT=	Dead simple tool to sign files and verify signatures
LICENSE=	isc

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
