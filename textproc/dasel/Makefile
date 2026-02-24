# $NetBSD: Makefile,v 1.17 2026/02/24 08:45:39 bsiegert Exp $

DISTNAME=	dasel-3.2.2
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=TomWright/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TomWright/dasel/
COMMENT=	Select, put and delete data from JSON, TOML, YAML, XML and CSV
LICENSE=	mit

USE_LANGUAGES=	c

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
