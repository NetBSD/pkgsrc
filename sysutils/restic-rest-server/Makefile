# $NetBSD: Makefile,v 1.34 2026/08/22 15:19:15 bsiegert Exp $

DISTNAME=	rest-server-0.14.0
PKGNAME=	restic-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	sysutils www
MASTER_SITES=	${MASTER_SITE_GITHUB:=restic/}
GITHUB_PROJECT=	rest-server
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/restic/rest-server
COMMENT=	REST server for restic
LICENSE=	mit

EXTRACT_USING=	bsdtar

GO_BUILD_PATTERN=	./cmd/rest-server

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
