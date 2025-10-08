# $NetBSD: Makefile,v 1.19 2025/10/08 06:54:30 bsiegert Exp $

DISTNAME=	k6-1.2.3
PKGREVISION=	1
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
