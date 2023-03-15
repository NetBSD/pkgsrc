# $NetBSD: Makefile,v 1.1 2023/03/15 20:22:51 schmonz Exp $

DISTNAME=		cli-3.1.0
PKGNAME=		${DISTNAME:S/^cli-/exercism-/}
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GITHUB:=exercism/}
GITHUB_PROJECT=		cli
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://exercism.org/
COMMENT=		Command line tool for exercism.org
LICENSE=		mit

USE_LANGUAGES=		# none

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
