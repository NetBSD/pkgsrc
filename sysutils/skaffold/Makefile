# $NetBSD: Makefile,v 1.5 2026/01/04 13:55:21 wiz Exp $

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

# NetBSD:
# vendor/github.com/buildpacks/pack/pkg/client/build.go:581:37: undefined: processVolumes
# SmartOS:
# vendor/github.com/AlecAivazis/survey/v2/terminal/runereader_posix.go:48:81: undefined: ioctlReadTermios
# vendor/github.com/AlecAivazis/survey/v2/terminal/runereader_posix.go:60:81: undefined: ioctlWriteTermios
# vendor/github.com/AlecAivazis/survey/v2/terminal/runereader_posix.go:68:81: undefined: ioctlWriteTermios
BROKEN=		"Does not build in any bulk build."

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
