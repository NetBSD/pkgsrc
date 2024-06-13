# $NetBSD: Makefile,v 1.20 2024/06/13 13:47:10 bsiegert Exp $

DISTNAME=	packer-1.9.5
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://www.packer.io/
COMMENT=	Tool for creating identical machine images for multiple platforms
LICENSE=	mpl-2.0

EXTRACT_USING=	bsdtar

.include "go-modules.mk"

GO_BUILD_PATTERN=	.
GO_XFLAG_PREFIX=	-X github.com/hashicorp/packer/version
GO_LDFLAGS+=		${GO_XFLAG_PREFIX}.Version=${PKGVERSION_NOREV}
INSTALLATION_DIRS+=	bin

do-build:
	${RUN}${_ULIMIT_CMD} cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} \
		${GO} install -v -ldflags ${GO_LDFLAGS:Q} ${GO_BUILD_PATTERN}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/packer ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
