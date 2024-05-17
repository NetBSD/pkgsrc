# $NetBSD: Makefile,v 1.139 2024/05/17 12:51:03 pin Exp $

DISTNAME=		oh-my-posh-19.30.0
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_GITHUB:=JanDeDobbeleer/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pin@NetBSD.org
HOMEPAGE=		https://ohmyposh.dev/
COMMENT=		Prompt theme engine for any shell
LICENSE=		mit

GO_VERSION_REQD+=	122

WRKSRC=			${WRKDIR}/${DISTNAME}/src

USE_LANGUAGES=		c

INSTALLATION_DIRS=	share/${PKGBASE}

GO_BUILD_DATE_cmd=	${DATE} "+%Y-%m-%d"
GO_FLAG_PREFIX=		github.com/jandedobbeleer/oh-my-posh/src
GO_BUILD_PATTERN=	-ldflags="-s -w -X '${GO_FLAG_PREFIX}/build.Version=${PKGVERSION_NOREV}' \
			-X '${GO_FLAG_PREFIX}/build.Date=${GO_BUILD_DATE_cmd:sh}'" ./...

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
