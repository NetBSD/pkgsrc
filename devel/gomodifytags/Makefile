# $NetBSD: Makefile,v 1.49 2026/11/10 18:55:06 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	gomodifytags-1.16.0
PKGREVISION=	48
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=fatih/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/fatih/gomodifytags/
COMMENT=	Go tool to modify struct field tags
LICENSE=	modified-bsd

GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
