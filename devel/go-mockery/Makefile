# $NetBSD: Makefile,v 1.17.2.1 2026/04/22 14:31:58 maya Exp $

DISTNAME=	mockery-3.5.4
PKGNAME=	go-${DISTNAME}
PKGREVISION=	9
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
