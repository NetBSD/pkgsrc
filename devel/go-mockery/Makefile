# $NetBSD: Makefile,v 1.27 2026/10/20 20:28:00 bsiegert Exp $

DISTNAME=	mockery-3.5.4
PKGNAME=	go-${DISTNAME}
PKGREVISION=	18
MASTER_SITES=	${MASTER_SITE_GITHUB:=vektra/}
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vektra.github.io/mockery/
COMMENT=	A mock code autogenerator for Go
LICENSE=	mit

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
