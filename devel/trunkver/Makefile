# $NetBSD: Makefile,v 1.16 2026/07/08 18:32:28 bsiegert Exp $

DISTNAME=	trunkver-1.1.0
PKGREVISION=	15
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=crftd-tech/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://trunkver.org/
COMMENT=	Versioning scheme for continuously delivered software
LICENSE=	mit

USE_LANGUAGES=	c

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
