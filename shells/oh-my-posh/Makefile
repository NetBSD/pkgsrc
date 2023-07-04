# $NetBSD: Makefile,v 1.38 2023/07/04 15:49:57 pin Exp $

DISTNAME=		oh-my-posh-17.6.0
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_GITHUB:=JanDeDobbeleer/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://ohmyposh.dev/
COMMENT=		Prompt theme engine for any shell
LICENSE=		mit

WRKSRC=			${WRKDIR}/${DISTNAME}/src

USE_LANGUAGES=		c

INSTALLATION_DIRS=	share/${PKGBASE}

GO_BUILD_PATTERN=	-ldflags="-s -w -X 'github.com/jandedobbeleer/oh-my-posh/src/build.Version=${PKGVERSION_NOREV}'" ./...

post-build:
	${MV} ${WRKDIR}/.gopath/bin/src ${WRKDIR}/.gopath/bin/oh-my-posh

post-install:
	cd ${WRKDIR}/${DISTNAME}/themes &&				\
	for f in *.json *.yaml; do					\
	  ${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/${PKGBASE};	\
	done

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
