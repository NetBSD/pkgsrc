# $NetBSD: Makefile,v 1.6 2025/09/06 13:17:08 bsiegert Exp $

DISTNAME=	gobuster-3.6.0
PKGREVISION=	5
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
