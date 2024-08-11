# $NetBSD: Makefile,v 1.17 2024/08/11 15:57:04 bsiegert Exp $

DISTNAME=	dnscontrol-3.27.1
PKGREVISION=	16
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=StackExchange/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dnscontrol.org/
COMMENT=	Opinionated platform for managing DNS configuration
LICENSE=	mit

INSTALLATION_DIRS+=	bin

# Only build dnscontrol, not the development tools `build', `generate',
# and `validate', which appear to be not terribly useful to install.
GO_BUILD_PATTERN=	.

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
