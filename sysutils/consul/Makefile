# $NetBSD: Makefile,v 1.20 2017/08/02 17:57:02 fhajny Exp $

DISTNAME=	consul-0.9.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=hashicorp/}

MAINTAINER=	filip@joyent.com
HOMEPAGE=	https://www.consul.io/
COMMENT=	Tool for service discovery, monitoring and configuration
LICENSE=	mpl-2.0

EXTRACT_USING=	bsdtar

GITHUB_TAG=	v${PKGVERSION_NOREV}

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/hashicorp/consul

USE_LANGUAGES=		c c99
USE_TOOLS+=		bash gmake

MAKE_ENV+=		GOPATH=${WRKDIR}:${PREFIX}/gopkg

INSTALLATION_DIRS+=	bin

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} go build -o bin/consul

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/consul ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
