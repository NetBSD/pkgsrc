# $NetBSD: Makefile,v 1.14 2024/08/11 15:57:12 bsiegert Exp $

DISTNAME=	rest-server-0.13.0
PKGNAME=	restic-${DISTNAME}
PKGREVISION=	1
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
