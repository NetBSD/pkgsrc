# $NetBSD: Makefile,v 1.31 2025/02/08 16:39:48 wiz Exp $

DISTNAME=	fq-0.14.0
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
