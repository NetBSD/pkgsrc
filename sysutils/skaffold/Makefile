# $NetBSD: Makefile,v 1.1 2025/09/07 18:43:37 maya Exp $

DISTNAME=	skaffold-2.16.1
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
