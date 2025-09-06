# $NetBSD: Makefile,v 1.53 2025/09/06 13:17:07 bsiegert Exp $

DISTNAME=		age-1.2.1
PKGREVISION=		6
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=FiloSottile/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/FiloSottile/age/
COMMENT=		Simple, modern and secure encryption tool
LICENSE=		modified-bsd

.include "go-modules.mk"

GO_BUILD_PATTERN=	-ldflags "-X main.Version=v${PKGVERSION_NOREV}"
GO_BUILD_PATTERN+=	filippo.io/age/cmd/...

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
