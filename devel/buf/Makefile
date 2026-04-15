# $NetBSD: Makefile,v 1.10 2026/04/15 06:29:52 adam Exp $

DISTNAME=	buf-1.68.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=bufbuild/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bufbuild/buf
COMMENT=	CLI tool for working with Protocol Buffers
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	./cmd/buf

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
