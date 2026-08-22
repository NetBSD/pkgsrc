# $NetBSD: Makefile,v 1.21 2026/08/22 15:18:57 bsiegert Exp $

DISTNAME=	buf-1.72.0
PKGREVISION=	2
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
