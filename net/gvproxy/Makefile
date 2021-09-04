# $NetBSD: Makefile,v 1.1 2021/09/04 20:19:29 maya Exp $

GITHUB_PROJECT=	gvisor-tap-vsock
GITHUB_TAG=	refs/tags/v0.1.0
DISTNAME=	v0.1.0
PKGNAME=	gvproxy-${DISTNAME:S,^v,,}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=containers/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/containers/gvisor-tap-vsock/
COMMENT=	Replacement for libslirp and VPNKit, written in pure Go
LICENSE=	apache-2.0

WRKSRC=	${WRKDIR}/gvisor-tap-vsock-0.1.0/cmd/gvproxy

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO} build -v

INSTALLATION_DIRS+=	bin
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gvproxy ${DESTDIR}${PREFIX}/bin/gvproxy

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
