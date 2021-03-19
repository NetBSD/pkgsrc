# $NetBSD: Makefile,v 1.26 2021/03/19 17:36:53 bsiegert Exp $

DISTNAME=	gopkgs-2.1.2
PKGNAME=	go-${DISTNAME}
PKGREVISION=	4
MASTER_SITES=	${MASTER_SITE_GITHUB:=uudashr/}
CATEGORIES=	devel
GITHUB_PROJECT=	gopkgs
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/uudashr/gopkgs
COMMENT=	Tool to get the list of available Go packages
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}/v2

GO_BUILD_PATTERN=	./cmd/gopkgs

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/gopkgs ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
