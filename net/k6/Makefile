# $NetBSD: Makefile,v 1.4 2024/03/24 21:01:34 leot Exp $

DISTNAME=	k6-0.49.0
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
