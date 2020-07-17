# $NetBSD: Makefile,v 1.9 2020/07/17 18:04:14 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	go-cpuid-1.2.1
GITHUB_PROJECT=	cpuid
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=klauspost/}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/klauspost/cpuid/
COMMENT=	CPU feature identification for Go
LICENSE=	modified-bsd

GO_SRCPATH=	github.com/klauspost/cpuid
GO_DIST_BASE=	cpuid-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
