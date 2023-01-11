# $NetBSD: Makefile,v 1.49 2023/01/11 17:28:27 bsiegert Exp $

DISTNAME=	gopkgs-2.1.2
PKGNAME=	go-${DISTNAME}
PKGREVISION=	26
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

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
