# $NetBSD: Makefile,v 1.22 2026/04/08 05:44:53 bsiegert Exp $

DISTNAME=	compiledb-go-1.5.4
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=fcying/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fcying/compiledb-go/
COMMENT=	Generate Clang's JSON Compilation Database for make-based builds
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
