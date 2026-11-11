# $NetBSD: Makefile,v 1.51.2.2 2026/11/11 20:32:02 maya Exp $

DISTNAME=	joker-1.10.0
PKGREVISION=	3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=candid82/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ktnb@NetBSD.org
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
