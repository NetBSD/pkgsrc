# $NetBSD: Makefile,v 1.1 2023/09/01 14:59:35 bacon Exp $

DISTNAME=	joker-1.3.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=candid82/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kevin.bloom@posteo.net
HOMEPAGE=	https://joker-lang.org/
COMMENT=	Clojure dialect and linter
LICENSE=	epl-v1.0

GO_BUILD_PATTERN=	.

pre-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV}	\
	    GOPATH=${WRKDIR}/.gopath ${GO} generate ./...

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
