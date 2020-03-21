# $NetBSD: Makefile,v 1.5 2020/03/21 16:57:16 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	go-cpuid-1.2.1
GITHUB_PROJECT=	cpuid
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=klauspost/}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/klauspost/cpuid/
COMMENT=	CPU feature identification for Go
LICENSE=	modified-bsd

GO_SRCPATH=	github.com/klauspost/cpuid
GO_DIST_BASE=	cpuid-${PKGVERSION_NOREV}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
