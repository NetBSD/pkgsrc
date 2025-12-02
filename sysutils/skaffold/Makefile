# $NetBSD: Makefile,v 1.4 2025/12/02 19:25:22 bsiegert Exp $

DISTNAME=	skaffold-2.16.1
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=GoogleContainerTools/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://skaffold.dev/
COMMENT=	Command line tool for Kubernetes application development
LICENSE=	apache-2.0

#WRKSRC=	${WRKDIR}/${DISTNAME}

GO_BUILD_PATTERN+=	./cmd/skaffold

DEPENDS+=	helm-[0-9]*:../../net/helm

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
