# $NetBSD: Makefile,v 1.10 2023/03/08 13:38:56 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	impl-1.1.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	9
GITHUB_PROJECT=	impl
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=josharian/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/josharian/impl/
COMMENT=	Generate method stubs for implementing an interface
LICENSE=	mit

GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
