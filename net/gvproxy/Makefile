# $NetBSD: Makefile,v 1.7 2022/01/09 20:10:36 bsiegert Exp $

DISTNAME=	gvproxy-0.1.0
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=containers/}
GITHUB_PROJECT=	gvisor-tap-vsock
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/containers/gvisor-tap-vsock/
COMMENT=	Replacement for libslirp and VPNKit, written in pure Go
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}/cmd/gvproxy

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO} build -v

INSTALLATION_DIRS+=	bin
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gvproxy ${DESTDIR}${PREFIX}/bin/gvproxy

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
