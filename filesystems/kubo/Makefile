# $NetBSD: Makefile,v 1.7 2023/03/09 09:19:59 wiz Exp $

DISTNAME=	kubo-0.18.1
PKGREVISION=	2
CATEGORIES=	filesystems net
MASTER_SITES=	${MASTER_SITE_GITHUB:=ipfs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ipfs/kubo/
COMMENT=	IPFS implementation in Go
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

# does not support go 1.20 yet (as of 0.18.1)
# ../.gopath/pkg/mod/github.com/lucas-clemente/quic-go@v0.31.1/internal/qtls/go120.go:5:13: cannot use "The version of quic-go you're using can't be built on Go 1.20 yet. For more details, please see https://github.com/lucas-clemente/quic-go/wiki/quic-go-and-Go-versions." (untyped string constant "The version of quic-go you're using can't be built on Go 1.20 yet. F...) as int value in variable declaration
GO_VERSION_DEFAULT=	119

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} build

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} install
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/ipfs ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
