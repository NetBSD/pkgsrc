# $NetBSD: Makefile,v 1.5 2023/01/03 14:42:53 wiz Exp $

DISTNAME=	syft-0.64.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=anchore/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/anchore/syft/
COMMENT=	Generate Software Bill of Materials from container images and file systems
LICENSE=	apache-2.0

USE_LANGUAGES=		c
GO_BUILD_PATTERN=	./cmd/syft

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
