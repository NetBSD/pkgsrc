# $NetBSD: Makefile,v 1.3 2024/01/16 21:47:09 wiz Exp $

DISTNAME=	trrntzip-1.1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=0-wiz-0/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://github.com/0-wiz-0/trrntzip/
COMMENT=	Create zip archives in a standard format
LICENSE=	gnu-gpl-v2 AND zlib

.include "../../devel/cmake/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
