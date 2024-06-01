# $NetBSD: Makefile,v 1.41 2024/06/01 14:02:49 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	asmfmt-1.3.2
PKGREVISION=	25
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=klauspost/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/klauspost/asmfmt/
COMMENT=	Go assembler formatter
LICENSE=	mit

GO_SRCPATH=		github.com/klauspost/asmfmt
GO_DIST_BASE=		${DISTNAME}
GO_BUILD_PATTERN=	github.com/klauspost/asmfmt/cmd/asmfmt

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
