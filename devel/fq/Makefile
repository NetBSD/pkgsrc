# $NetBSD: Makefile,v 1.19 2024/01/10 19:14:27 bsiegert Exp $

DISTNAME=	fq-0.9.0
PKGREVISION=	2
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
