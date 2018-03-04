# $NetBSD: Makefile,v 1.24 2018/03/04 15:52:19 bsiegert Exp $

DISTNAME=	vault-0.9.5
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
