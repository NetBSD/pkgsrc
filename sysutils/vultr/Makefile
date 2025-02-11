# $NetBSD: Makefile,v 1.71 2025/02/11 08:41:43 wiz Exp $

DISTNAME=		vultr-2.0.3
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
