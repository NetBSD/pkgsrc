# $NetBSD: Makefile,v 1.41 2024/06/01 14:02:59 bsiegert Exp $

DISTNAME=		age-1.1.1
PKGREVISION=		15
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=FiloSottile/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/FiloSottile/age/
COMMENT=		Simple, modern and secure encryption tool
LICENSE=		modified-bsd

.include "go-modules.mk"

GO_BUILD_PATTERN=	filippo.io/age/cmd/...

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
