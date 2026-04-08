# $NetBSD: Makefile,v 1.13 2026/04/08 05:45:07 bsiegert Exp $

DISTNAME=	gobuster-3.6.0
PKGREVISION=	12
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=OJ/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OJ/gobuster/
COMMENT=	Service explorer
LICENSE=	apache-2.0

USE_LANGUAGES=	c

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
