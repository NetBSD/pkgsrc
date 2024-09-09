# $NetBSD: Makefile,v 1.4 2024/09/09 10:31:45 nia Exp $

DISTNAME=	minikube-1.33.1
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=kubernetes/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kubernetes/minikube/
COMMENT=	Local kubernetes cluster
LICENSE=	apache-2.0

USE_LANGUAGES+=	c
USE_TOOLS+=	gmake

BINNAME=	minikube-${OPSYS:tl}-${GOARCH}
BUILD_TARGET+=	${BINNAME}
MAKE_ENV+=	V=1

ONLY_FOR_PLATFORM=	Darwin-*-aarch64
ONLY_FOR_PLATFORM+=	Darwin-*-x86_64
ONLY_FOR_PLATFORM+=	Linux-*-aarch64
ONLY_FOR_PLATFORM+=	Linux-*-x86_64

do-build:
	cd ${WRKSRC} && \
	${RUN} ${_ULIMIT_CMD} \
	${PKGSRC_SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} ${BUILD_MAKE_FLAGS} \
			${BUILD_TARGET}

INSTALLATION_DIRS+=	bin
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out/${BINNAME} ${DESTDIR}${PREFIX}/bin/minikube

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
