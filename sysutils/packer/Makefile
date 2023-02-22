# $NetBSD: Makefile,v 1.1 2023/02/22 11:58:24 jperkin Exp $

DISTNAME=	packer-1.8.6
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://www.packer.io/
COMMENT=	Tool for creating identical machine images for multiple platforms
LICENSE=	mpl-2.0

EXTRACT_USING=	bsdtar

.include "go-modules.mk"

GO_BUILD_PATTERN=	.
CHECK_RELRO_SKIP+=	bin/packer
INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/packer ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
