# $NetBSD: Makefile,v 1.28 2026/08/31 19:18:59 bsiegert Exp $

DISTNAME=	scaleway-cli-2.56.1
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=scaleway/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.scaleway.com/en/cli/
COMMENT=	Command Line Interface for Scaleway
LICENSE=	apache-2.0

# fails to build with Go 1.27
GO_VERSION_REQD=		126

GOFLAGS+=		-ldflags ' \
			-X main.Version=${PKGVERSION_NOREV} \
			-X main.GitCommit= \
			-X main.GitBranch= \
			-X main.BuildDate='
GO_BUILD_PATTERN=	./cmd/scw

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
