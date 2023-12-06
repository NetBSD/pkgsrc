# $NetBSD: Makefile,v 1.33.2.2 2023/12/06 12:08:39 spz Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	asmfmt-1.3.2
PKGREVISION=	19
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
