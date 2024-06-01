# $NetBSD: Makefile,v 1.14 2024/06/01 14:02:55 bsiegert Exp $

DISTNAME=	dnscontrol-3.27.1
PKGREVISION=	13
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
