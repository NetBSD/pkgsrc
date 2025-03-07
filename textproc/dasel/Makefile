# $NetBSD: Makefile,v 1.3 2025/03/07 20:54:31 bsiegert Exp $

DISTNAME=	dasel-2.8.1
PKGREVISION=	2
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
