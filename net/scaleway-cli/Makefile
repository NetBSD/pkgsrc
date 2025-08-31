# $NetBSD: Makefile,v 1.11 2025/08/31 10:02:54 bsiegert Exp $

DISTNAME=	scaleway-cli-2.42.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=scaleway/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.scaleway.com/en/cli/
COMMENT=	Command Line Interface for Scaleway
LICENSE=	apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.Version=${PKGVERSION_NOREV} \
			-X main.GitCommit= \
			-X main.GitBranch= \
			-X main.BuildDate='
GO_BUILD_PATTERN+=	./cmd/scw

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
