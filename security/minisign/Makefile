# $NetBSD: Makefile,v 1.2 2020/06/07 11:04:43 fcambus Exp $

DISTNAME=	minisign-0.9
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=jedisct1/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://github.com/jedisct1/minisign/
COMMENT=	Dead simple tool to sign files and verify signatures
LICENSE=	isc

USE_CMAKE=	yes

.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
