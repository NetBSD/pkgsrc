# $NetBSD: Makefile,v 1.42 2025/12/02 19:25:17 bsiegert Exp $

VERSION=	2.20.0
DISTNAME=	vultr-cli-${VERSION}
PKGREVISION=	17
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=vultr/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vultr/vultr-cli/
COMMENT=	Official command line tool for Vultr services
LICENSE=	apache-2.0

GO_BUILD_PATTERN=	.

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/vultr-cli ${DESTDIR}${PREFIX}/bin/vultr-cli

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
