# $NetBSD: Makefile,v 1.37 2026/01/15 19:54:40 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	impl-1.4.0
PKGNAME=	go-${DISTNAME}
PKGREVISION=	8
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
