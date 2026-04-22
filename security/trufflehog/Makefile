# $NetBSD: Makefile,v 1.44.2.1 2026/04/22 14:32:14 maya Exp $

DISTNAME=	trufflehog-3.90.5
PKGREVISION=	8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=trufflesecurity/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/trufflesecurity/trufflehog
COMMENT=	Find credentials all over the place
LICENSE=	gnu-agpl-v3

GOFLAGS+=		-ldflags ' \
			-X github.com/trufflesecurity/trufflehog/v3/pkg/version.BuildVersion=${GITHUB_TAG}'
GO_BUILD_PATTERN=	.

# github.com/wasilibs/go-re2 needs NOT_PAX_MPROTECT_SAFE, stick to Go regexp to
# avoid that.
SUBST_CLASSES+=		regexp
SUBST_STAGE.regexp=	pre-configure
SUBST_FILES.regexp+=	pkg/detectors/*.go
SUBST_FILES.regexp+=	pkg/detectors/*/*.go
SUBST_FILES.regexp+=	pkg/detectors/*/*/*.go
SUBST_FILES.regexp+=	pkg/detectors/*/*/*/*.go
SUBST_MESSAGE.regexp=	Stick to Go regexp to avoid requiring NOT_PAX_MPROTECT_SAFE
SUBST_SED.regexp+=	-e 's,regexp "github.com/wasilibs/go-re2","regexp",g'

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
