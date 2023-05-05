# $NetBSD: Makefile,v 1.5 2023/05/05 19:37:42 bsiegert Exp $

DISTNAME=	shfmt-3.6.0
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mvdan/}
GITHUB_PROJECT=	sh
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mvdan/sh
COMMENT=	Shell formatter with bash support
LICENSE=	modified-bsd

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.version=${GITHUB_TAG}'
GO_BUILD_PATTERN+=	./cmd/shfmt

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
