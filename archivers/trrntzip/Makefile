# $NetBSD: Makefile,v 1.1 2022/06/17 23:05:04 wiz Exp $

DISTNAME=	trrntzip-1.0
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GITHUB:=0-wiz-0/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://github.com/0-wiz-0/trrntzip/
COMMENT=	Create zip archives in a standard format
LICENSE=	gnu-gpl-v2 AND zlib

USE_CMAKE=	yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
