# $NetBSD: Makefile,v 1.40 2026/05/07 18:49:55 bsiegert Exp $

DISTNAME=	shfmt-3.13.1
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mvdan/}
GITHUB_PROJECT=	sh
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mvdan/sh
COMMENT=	Shell formatter with bash support
LICENSE=	modified-bsd

GOFLAGS+=		-ldflags ' \
			-X main.version=${GITHUB_TAG}'
GO_BUILD_PATTERN=	./cmd/shfmt

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
