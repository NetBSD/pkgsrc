# $NetBSD: Makefile,v 1.6 2025/09/06 13:17:00 bsiegert Exp $

DISTNAME=	trunkver-1.1.0
PKGREVISION=	5
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
