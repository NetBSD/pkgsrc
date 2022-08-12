# $NetBSD: Makefile,v 1.2 2022/08/12 20:38:04 bsiegert Exp $

DISTNAME=	trufflehog-3.7.2
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=trufflesecurity/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/trufflesecurity/trufflehog
COMMENT=	Find credentials all over the place
LICENSE=	gnu-agpl-v3

GO_BUILD_PATTERN+=	-ldflags ' \
			-X github.com/trufflesecurity/trufflehog/v3/pkg/version.BuildVersion=${GITHUB_TAG}'

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
