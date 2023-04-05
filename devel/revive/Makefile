# $NetBSD: Makefile,v 1.7 2023/04/05 20:47:59 bsiegert Exp $

DISTNAME=	revive-1.2.4
PKGNAME=	go-${DISTNAME}
PKGREVISION=	6
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
