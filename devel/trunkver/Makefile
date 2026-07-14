# $NetBSD: Makefile,v 1.15.2.1 2026/07/14 00:35:50 maya Exp $

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
