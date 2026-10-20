# $NetBSD: Makefile,v 1.44 2026/10/20 20:28:04 bsiegert Exp $

DISTNAME=	revive-1.2.4
PKGNAME=	go-${DISTNAME}
PKGREVISION=	43
MASTER_SITES=	${MASTER_SITE_GITHUB:=mgechev/}
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	revive

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mgechev/revive/
COMMENT=	Linter for Go
LICENSE=	mit

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
