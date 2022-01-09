# $NetBSD: Makefile,v 1.13 2022/01/09 20:10:31 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	asmfmt-1.3.0
PKGREVISION=	8
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
