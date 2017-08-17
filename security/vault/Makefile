# $NetBSD: Makefile,v 1.15 2017/08/17 07:58:53 fhajny Exp $

DISTNAME=	vault-0.8.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.vaultproject.io/
COMMENT=	Tool for managing secrets
LICENSE=	mpl-2.0

GITHUB_TAG=	v${PKGVERSION_NOREV}

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/hashicorp/vault

USE_TOOLS+=		bash gmake

MAKE_ENV+=		GOPATH=${WRKDIR}:${PREFIX}/gopkg

INSTALLATION_DIRS+=	bin

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} go build -o bin/vault

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vault ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
