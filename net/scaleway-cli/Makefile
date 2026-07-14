# $NetBSD: Makefile,v 1.23.2.1 2026/07/14 00:35:57 maya Exp $

DISTNAME=	scaleway-cli-2.56.1
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=scaleway/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.scaleway.com/en/cli/
COMMENT=	Command Line Interface for Scaleway
LICENSE=	apache-2.0

GOFLAGS+=		-ldflags ' \
			-X main.Version=${PKGVERSION_NOREV} \
			-X main.GitCommit= \
			-X main.GitBranch= \
			-X main.BuildDate='
GO_BUILD_PATTERN=	./cmd/scw

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
