# $NetBSD: Makefile,v 1.11 2024/06/13 13:47:10 bsiegert Exp $

DISTNAME=	rest-server-0.12.1
PKGNAME=	restic-${DISTNAME}
PKGREVISION=	8
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
