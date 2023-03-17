# $NetBSD: Makefile,v 1.2 2023/03/17 11:23:57 schmonz Exp $

DISTNAME=		oh-my-posh-14.14.3
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_GITHUB:=JanDeDobbeleer/}
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://ohmyposh.dev/
COMMENT=		Prompt theme engine for any shell
LICENSE=		mit

WRKSRC=			${WRKDIR}/${DISTNAME}/src

USE_LANGUAGES=		c

SUBST_CLASSES+=		version
SUBST_STAGE.version=	do-configure
SUBST_FILES.version=	main.go
SUBST_SED.version=	-e 's|"development"|"${PKGVERSION_NOREV}"|'

INSTALLATION_DIRS=	share/${PKGBASE}

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
