# $NetBSD: Makefile,v 1.42 2026/08/27 07:40:46 drixter Exp $

DISTNAME=	dnscontrol-5.0.0
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

GO_VERSION_REQD=	127

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
