# $NetBSD: Makefile,v 1.35 2025/08/31 09:48:03 bsiegert Exp $

DISTNAME=	trufflehog-3.63.7
PKGREVISION=	11
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=trufflesecurity/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/trufflesecurity/trufflehog
COMMENT=	Find credentials all over the place
LICENSE=	gnu-agpl-v3

# TODO: fix build of this package with Go 1.25 and remove this line
GO_VERSION_DEFAULT=	124

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/trufflesecurity/trufflehog/v3/pkg/version.BuildVersion=${GITHUB_TAG}'

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
