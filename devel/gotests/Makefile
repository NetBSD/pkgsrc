# $NetBSD: Makefile,v 1.29 2025/04/05 18:51:15 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	gotests-1.6.0
PKGREVISION=	28
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=cweill/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/cweill/gotests/
COMMENT=	Automatically generate Go test boilerplate from your source code
LICENSE=	apache-2.0

GO_BUILD_PATTERN=	./gotests

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
