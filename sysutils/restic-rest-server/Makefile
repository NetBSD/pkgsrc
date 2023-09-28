# $NetBSD: Makefile,v 1.1 2023/09/28 22:03:10 joerg Exp $

DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
PKGNAME=	restic-reset-server-0.12.0
CATEGORIES=	sysutils www
MASTER_SITES=	${MASTER_SITE_GITHUB:=restic/}
GITHUB_PROJECT=	rest-server
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://restic.net/
COMMENT=	REST server for restic
LICENSE=	mit

EXTRACT_USING=	bsdtar

GO_BUILD_PATTERN=	./cmd/rest-server

.include "go-modules.mk"


.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
