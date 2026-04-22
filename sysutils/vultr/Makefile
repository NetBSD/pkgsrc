# $NetBSD: Makefile,v 1.82.2.1 2026/04/22 14:32:17 maya Exp $

DISTNAME=		vultr-2.0.3
PKGREVISION=		12
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=JamesClonk/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://jamesclonk.github.io/vultr/
COMMENT=		CLI and API client library for Vultr
LICENSE=		mit

USE_LANGUAGES=		c

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
