# $NetBSD: Makefile,v 1.10 2024/03/11 07:44:15 wiz Exp $

DISTNAME=	joker-1.3.5
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=candid82/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ktnb@posteo.net
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
