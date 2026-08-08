# $NetBSD: Makefile,v 1.39 2026/08/08 19:16:18 drixter Exp $

DISTNAME=	dnscontrol-4.46.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=StackExchange/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
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
