# $NetBSD: Makefile,v 1.103 2024/06/13 13:47:08 bsiegert Exp $

DISTNAME=	vault-1.6.6
PKGREVISION=	34
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.vaultproject.io/
COMMENT=	Tool for managing secrets
LICENSE=	mpl-2.0

GITHUB_TAG=	v${PKGVERSION_NOREV}

GO_DIST_BASE=		${DISTNAME}
GO_SRCPATH=		github.com/hashicorp/vault
# no "..." suffix here, triggered upstream ticket #10330 and #10638
GO_BUILD_PATTERN=	${GO_SRCPATH}/

USE_TOOLS+=		bash gmake

INSTALLATION_DIRS+=	bin

DEPENDS+=	go>=1.15.15:../../lang/go

# Clumsy workaround for https://github.com/golang/go/issues/22409
pre-build:
	${RM} -rf ${WRKSRC}/vault/external_tests

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/vault ${DESTDIR}${PREFIX}/bin

do-test:
	cd ${WRKSRC} && ${SETENV} GOPATH=${WRKDIR}:${BUILDLINK_DIR}/gopkg ${GO} test -v ./vault

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
