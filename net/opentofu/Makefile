# $NetBSD: Makefile,v 1.4 2024/06/13 13:47:04 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	opentofu-1.6.2
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=opentofu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://opentofu.org
COMMENT=	Free infrastructure orchestration tool
LICENSE=	mpl-2.0

GO_BUILD_PATTERN=	./cmd/tofu

USE_LANGUAGES+=	c		# something here uses cgo

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
