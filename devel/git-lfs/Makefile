# $NetBSD: Makefile,v 1.36 2021/07/13 11:36:39 bsiegert Exp $

DISTNAME=	git-lfs-2.13.3
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=git-lfs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git-lfs.github.com/
COMMENT=	Git extension for versioning large files
LICENSE=	mit

NO_CONFIGURE=	yes
USE_LANGUAGES=	c
GO_BUILD_PATTERN=	.

INSTALLATION_DIRS=	bin

pre-build:
	cp ${WRKSRC}/lfshttp/certs_openbsd.go ${WRKSRC}/lfshttp/certs_netbsd.go
# generate content for "git-lfs --help"
	ln -sf ${GO} ${BUILDLINK_DIR}/bin/go
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} GOPATH=${WRKDIR} ${GO} generate ./commands

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/git-lfs ${DESTDIR}${PREFIX}/bin/git-lfs

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
