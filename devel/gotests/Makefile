# $NetBSD: Makefile,v 1.39.2.1 2026/04/22 14:32:01 maya Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	gotests-1.9.0
PKGREVISION=	4
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
