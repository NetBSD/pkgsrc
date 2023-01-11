# $NetBSD: Makefile,v 1.3 2023/01/11 17:28:29 bsiegert Exp $

DISTNAME=	kubo-0.17.0
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

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} build

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} install
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/ipfs ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
