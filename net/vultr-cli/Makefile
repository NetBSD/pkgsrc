# $NetBSD: Makefile,v 1.45 2026/03/06 21:07:59 bsiegert Exp $

VERSION=	2.20.0
DISTNAME=	vultr-cli-${VERSION}
PKGREVISION=	20
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
