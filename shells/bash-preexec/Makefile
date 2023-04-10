# $NetBSD: Makefile,v 1.1 2023/04/10 13:59:38 schmonz Exp $

DISTNAME=		bash-preexec-0.5.0
CATEGORIES=		shells
MASTER_SITES=		${MASTER_SITE_GITHUB:=rcaloras/}
GITHUB_TAG=		${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/rcaloras/bash-preexec/
COMMENT=		Preexec and precmd hook functions a la zsh
LICENSE=		mit

USE_LANGUAGES=		# none
NO_BUILD=		yes
INSTALLATION_DIRS=	${PREFIX}/share/${PKGBASE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PKGBASE}.sh ${DESTDIR}${PREFIX}/share/${PKGBASE}/

.include "../../mk/bsd.pkg.mk"
