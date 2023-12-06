# $NetBSD: Makefile,v 1.12.2.2 2023/12/06 12:08:39 spz Exp $

DISTNAME=	fq-0.7.0
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=wader/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wader/fq/
COMMENT=	File parsing tool like jq, but for binary files
LICENSE=	mit

GO_BUILD_PATTERN+=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
