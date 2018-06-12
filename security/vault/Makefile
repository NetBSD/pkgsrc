# $NetBSD: Makefile,v 1.29 2018/06/12 17:50:27 bsiegert Exp $

DISTNAME=	vault-0.10.1
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://www.vaultproject.io/
COMMENT=	Tool for managing secrets
LICENSE=	mpl-2.0

GITHUB_TAG=	v${PKGVERSION_NOREV}

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/hashicorp/vault

USE_TOOLS+=		bash gmake

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/vault ${DESTDIR}${PREFIX}/bin

do-test:
	cd ${WRKSRC} && ${SETENV} GOPATH=${WRKDIR}:${BUILDLINK_DIR}/gopkg go test -v ./vault

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
