# $NetBSD: Makefile,v 1.23 2026/07/08 18:32:33 bsiegert Exp $

DISTNAME=	opentofu-1.12.3
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=opentofu/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opentofu.org/
COMMENT=	Free infrastructure orchestration tool
LICENSE=	mpl-2.0

GO_BUILD_PATTERN=	./cmd/tofu

USE_LANGUAGES=		c # something uses cgo

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
