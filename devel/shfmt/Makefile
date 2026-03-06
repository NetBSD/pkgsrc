# $NetBSD: Makefile,v 1.36 2026/03/06 21:07:52 bsiegert Exp $

DISTNAME=	shfmt-3.12.0
PKGREVISION=	8
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
