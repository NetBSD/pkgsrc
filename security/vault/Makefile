# $NetBSD: Makefile,v 1.5 2016/10/26 11:49:11 fhajny Exp $

DISTNAME=	vault-0.6.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.vaultproject.io/
COMMENT=	Tool for managing secrets
LICENSE=	mpl-2.0

GITHUB_TAG=	v${PKGVERSION_NOREV}

WRKSRC=		${WRKDIR}/src/github.com/hashicorp/vault

.include "../../lang/go/version.mk"

BUILD_DEPENDS+=		go-${GO_VERSION}*:../../lang/go

USE_TOOLS+=		bash gmake

MAKE_ENV+=		GOPATH=${WRKDIR}:${PREFIX}/gopkg

INSTALLATION_DIRS+=	bin

post-extract:
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/${DISTNAME}/* ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} go build -o bin/vault

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vault ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
