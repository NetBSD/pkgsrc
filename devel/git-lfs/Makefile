# $NetBSD: Makefile,v 1.51 2022/07/13 16:03:06 bsiegert Exp $

DISTNAME=	git-lfs-3.1.2
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

pre-build:
# generate content for "git-lfs --help"
	ln -sf ${GO} ${BUILDLINK_DIR}/bin/go
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV}	\
	    GOPATH=${WRKDIR}/.gopath ${GO} generate ./commands

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
