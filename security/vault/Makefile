# $NetBSD: Makefile,v 1.127 2026/09/13 14:17:13 bsiegert Exp $

DISTNAME=	vault-1.6.6
PKGREVISION=	57
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.vaultproject.io/
COMMENT=	Tool for managing secrets
LICENSE=	mpl-2.0

GITHUB_TAG=	v${PKGVERSION_NOREV}

GO_BUILD_PATTERN=	.

USE_TOOLS+=		bash gmake

INSTALLATION_DIRS+=	bin

# Clumsy workaround for https://github.com/golang/go/issues/22409
pre-build:
	${RM} -rf ${WRKSRC}/vault/external_tests

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${GOPATH_BIN}/vault ${DESTDIR}${PREFIX}/bin

do-test:
	cd ${WRKSRC} && ${SETENV} GOPATH=${WRKDIR}:${BUILDLINK_DIR}/gopkg ${GO} test -v ./vault

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
