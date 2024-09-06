# $NetBSD: Makefile,v 1.5 2024/09/06 18:48:44 bsiegert Exp $

DISTNAME=	mockery-2.43.2
PKGNAME=	go-${DISTNAME}
PKGREVISION=	4
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
