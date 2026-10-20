# $NetBSD: Makefile,v 1.36 2026/10/20 20:28:08 bsiegert Exp $

DISTNAME=	k6-1.5.0
PKGREVISION=	12
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=grafana/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://k6.io/
COMMENT=	Modern load testing tool using Go and JavaScript
LICENSE=	gnu-agpl-v3

# Install only k6 (gen is build but not intended to be installed)
do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/k6 ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
