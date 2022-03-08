# $NetBSD: Makefile,v 1.46 2022/03/08 08:33:03 wiz Exp $
#
# Release notes:
# https://github.com/golang/tools/releases

DISTNAME=	gopls-0.8.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=	tools
GITHUB_TAG=	gopls/v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://pkg.go.dev/golang.org/x/tools/gopls
COMMENT=	LSP server for Go editor integration
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/tools-${GITHUB_TAG:S/\//-/}/gopls

GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
